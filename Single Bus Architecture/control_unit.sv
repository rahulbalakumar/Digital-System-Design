module control_unit #(
    parameter int WIDTH = 16
)(
    input logic clk,
    input logic rst_n, // Active low reset
    input logic [WIDTH-1:0] ir_out, // Input from Instruction Register

    // Controls to the bus's multiplexer
    output logic [2:0] bus_sel,
    output logic [WIDTH-1:0] imm_val, // To feed immediate values to the bus

    // Enable signals for Register Write
    output logic pc_wr_en,
    output logic ir_wr_en,
    output logic mar_wr_en,
    output logic y_wr_en,
    output logic z_wr_en,
    output logic mdr_bus_wr_en,

    // Control signals for the register file
    output logic reg_wr_en,
    output logic [2:0] reg_rd_addr,
    output logic [2:0] reg_wr_addr,

    // ALU Control signals
    output logic [2:0] alu_op,

    // External memory controls
    output logic mem_read,
    output logic mdr_mem_wr_en // Enables MDR to capture data from external memory
);

    // Instruction decoding

    logic [3:0] opcode; // 4 bit opcode
    logic [2:0] rd, rs1, rs2; // 3 bits for register specifications

    assign opcode = ir_out[15:12];
    assign rd = ir_out[11:9];
    assign rs1 = ir_out[8:6];
    assign rs2 = ir_out[5:3];

    // Bus Multiplexer encoding
    localparam SEL_NONE = 3'd0;
    localparam SEL_PC = 3'd1;
    localparam SEL_Z = 3'd2;
    localparam SEL_MDR = 3'd3;
    localparam SEL_REG = 3'd4;
    localparam SEL_IMM = 3'd5;

    // FSM
    typedef enum logic [3:0] {
        // Fetch states
        FETCH_1, FETCH_2, FETCH_3, FETCH_4, FETCH_5,
        // Execution states (Included Decode state as well)
        DECODE, ADD_1, ADD_2, ADD_3, LOAD_1, LOAD_2, LOAD_3
    } state_t;

    state_t current_state, next_state;

    // State register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) current_state <= FETCH_1;
        else current_state <= next_state;
    end

    // Next state and output logic
    always_comb begin
        // Setting defaults
        bus_sel = SEL_NONE;
        imm_val = '0;
        pc_wr_en = 0;
        ir_wr_en = 0;
        mar_wr_en = 0;
        y_wr_en = 0;
        z_wr_en = 0;
        mdr_bus_wr_en = 0;
        reg_wr_en = 0;
        reg_rd_addr = '0;
        reg_wr_addr = '0;
        alu_op = 3'b000; // Setting ALU Default as ADD
        mem_read = 0;
        mdr_mem_wr_en = 0;
        next_state = current_state;

        case (current_state)

            // FETCH CYCLE

            // First step: Sending PC to MAR to read next instruction's address
            FETCH_1: begin
                bus_sel = SEL_PC;
                mar_wr_en = 1;
                next_state = FETCH_2;
            end

            // Second step: Read memory into MDR and Put PC into Y to increment PC and get the next instruction
            FETCH_2: begin
                mem_read = 1;
                mdr_mem_wr_en = 1; // MDR reads data from external memory
                bus_sel = SEL_PC;
                y_wr_en = 1; // PC loaded onto Y
                next_state = FETCH_3;
            end

            // Third step: Incrementing PC, adding Y and the Bus's immediate 1 and putting the result into reg z
            FETCH_3: begin
                bus_sel = SEL_IMM;
                imm_val = 16'd1;
                alu_op = 3'b000; // ADD
                z_wr_en = 1; // Z captures alu output (Y=PC + 1)
                next_state = FETCH_4;
            end

            // Fourth step: Write incremented PC back into PC register
            FETCH_4: begin
                bus_sel = SEL_Z;
                pc_wr_en = 1;
                next_state = FETCH_5;
            end

            // Fifth step: Transfer next instruction from MDR to IR
            FETCH_5: begin
                bus_sel = SEL_MDR;
                ir_wr_en = 1;
                next_state = DECODE; // New instruction has been loaded into IR hence next is to decode it
            end

            // DECODE CYCLE
            DECODE: begin
                case(opcode)
                    4'b0001: next_state = ADD_1;
                    4'b0010: next_state = LOAD_1;
                    default: next_state = FETCH_1; // Revert to fetch since opcode is unknown
                endcase
            end

            // EXECUTE CYCLE : ADD

            // Get rs1 and put it in reg Y
            ADD_1: begin
                reg_rd_addr = rs1;
                bus_sel = SEL_REG;
                y_wr_en = 1; 
                next_state = ADD_2;
            end

            // Get rs2, and ALU adds rs2 and rs1 and put it in reg Z
            ADD_2: begin
                reg_rd_addr = rs2;
                bus_sel = SEL_REG;
                alu_op = 3'b000; // ADD
                z_wr_en = 1;
                next_state = ADD_3;
            end

            // Write Z into Register File
            ADD_3: begin
                bus_sel = SEL_Z;
                reg_wr_addr = rd;
                reg_wr_en = 1;
                next_state = FETCH_1; // Get the next instruction
            end

            // EXECUTE CYCLE : LOAD

            // Read Rs1's address and send to MAR
            LOAD_1: begin
                reg_rd_addr = rs1;
                bus_sel = SEL_REG;
                mar_wr_en = 1;
                next_state = LOAD_2;
            end

            // Read from external memory into MDR
            LOAD_2: begin
                mem_read = 1;
                mdr_mem_wr_en = 1;
                next_state = LOAD_3;
            end

            // Write MDR into the destination register (Register File)
            LOAD_3: begin
                bus_sel = SEL_REG;
                reg_wr_addr = rd;
                reg_wr_en = 1;
                next_state = FETCH_1; // Get the next instruction
            end

            default: next_state = FETCH_1;
        endcase
    end
endmodule
