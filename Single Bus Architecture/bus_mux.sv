module bus_mux #(
    parameter int WIDTH = 16
)(
    // Control signal from control unit
    input logic [2:0] bus_sel,

    // Data sources that connect to the shared bus
    input logic [WIDTH-1:0] pc_out, // Program Counter
    input logic [WIDTH-1:0] z_out, // ALU result from register Z
    input logic [WIDTH-1:0] mdr_out, // Memory data register
    input logic [WIDTH-1:0] reg_rd_data, // Data from register file
    input logic [WIDTH-1:0] imm_val, // Immediate value from instruction

    // Shared bus output
    output logic [WIDTH-1:0] bus_out
);

    // Multiplexer selections
    localparam SEL_NONE = 3'd0; // Drives 0
    localparam SEL_PC = 3'd1; // Drives PC
    localparam SEL_Z = 3'd2; // Drives ALU result from register Z
    localparam SEL_MDR = 3'd3; // Drives MDR
    localparam SEL_REG = 3'd4; // Drives register file
    localparam SEL_IMM = 3'd5; 

    always_comb begin
        case (bus_sel)
            SEL_PC: bus_out <= pc_out;
            SEL_Z: bus_out <= z_out;
            SEL_MDR: bus_out <= mdr_out;
            SEL_REG: bus_out <= reg_rd_data;
            SEL_IMM: bus_out <= imm_val;
            default: bus_out <= '0; // Bus drives 0 when IDLE
        endcase
    end
endmodule