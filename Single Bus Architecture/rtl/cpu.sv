module cpu #(
    parameter int WIDTH = 16
)(
    input logic clk,
    input logic rst_n, // Active low reset

    // External memory interface
    output logic [WIDTH-1:0] mem_addr, // Address going out to external memory
    output logic mem_read, // To read from external memory
    output logic mem_write, // To write to external memory
    input logic [WIDTH-1:0] mem_data_in, // Data coming into CPU from memory
    output logic [WIDTH-1:0] mem_data_out // Data coming into memory from CPU 
);

    // Shared bus
    logic [WIDTH-1:0] shared_bus;

    // Data outputs from special registers
    logic [WIDTH-1:0] pc_out, ir_out, mar_out, y_out, z_out, mdr_out;

    // Register file outputs
    logic [WIDTH-1:0] reg_rd_data;

    // ALU wires
    logic [WIDTH-1:0] alu_result;
    logic alu_zero;

    // Control signals from control unit
    logic [2:0] bus_sel;
    logic [WIDTH-1:0] imm_val;
    logic pc_wr_en, ir_wr_en, mar_wr_en, y_wr_en, z_wr_en;
    logic mdr_bus_wr_en, mdr_mem_wr_en;
    logic reg_wr_en;
    logic [2:0] reg_rd_addr, reg_wr_addr;
    logic [2:0] alu_op;

    // Instantiation of the ALU
    alu #(
        .WIDTH(WIDTH)
    ) u_alu (
        .a(y_out), // Input A comes from register Y
        .b(shared_bus), // Input B is connected to the shared bus
        .alu_op(alu_op), // Control signals to the alu to select function
        .result(alu_result), // Output of ALU to the register Z
        .zero(alu_zero) // Flag for zero
    );

    // Instantiation of the Register File
    reg_file #(
        .WIDTH(WIDTH),
        .REG_COUNT(8)
    ) u_reg_file (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(reg_wr_en),
        .wr_addr(reg_wr_addr),
        .wr_data(shared_bus), // Registers get written from the Shared bus
        .rd_addr(reg_rd_addr),
        .rd_data(reg_rd_data) // Output to the bus multiplexer
    );

    special_regs #(
        .WIDTH(WIDTH)
    ) u_special_regs (
        .clk(clk),
        .rst_n(rst_n),
        .bus_in(shared_bus),
        .mem_data_in(mem_data_in), // Data from external memory
        .alu_result(alu_result), // Directly connected to the ALU, not via the bus
        .pc_wr_en(pc_wr_en),
        .ir_wr_en(ir_wr_en),
        .mar_wr_en(mar_wr_en),
        .y_wr_en(y_wr_en),
        .z_wr_en(z_wr_en),
        .mdr_bus_wr_en(mdr_bus_wr_en),
        .mdr_mem_wr_en(mdr_mem_wr_en),
        .pc_out(pc_out),
        .ir_out(ir_out),
        .mar_out(mar_out),
        .y_out(y_out),
        .z_out(z_out),
        .mdr_out(mdr_out)
    );

    // Bus Multiplexer
    bus_mux #(
        .WIDTH(WIDTH)
    ) u_bus_mux (
        .bus_sel(bus_sel),
        .pc_out(pc_out),
        .z_out(z_out),
        .mdr_out(mdr_out),
        .reg_rd_data(reg_rd_data),
        .imm_val(imm_val), // Immediate values directly from the control unit
        .bus_out(shared_bus)
    );

    control_unit #(
        .WIDTH(WIDTH)
    ) u_control_unit (
        .clk(clk),
        .rst_n(rst_n),
        .ir_out(ir_out), // Input to the Control unit from the Instruction Register
        .bus_sel(bus_sel),
        .imm_val(imm_val),
        .pc_wr_en(pc_wr_en),
        .ir_wr_en(ir_wr_en),
        .mar_wr_en(mar_wr_en),
        .y_wr_en(y_wr_en),
        .z_wr_en(z_wr_en),
        .mdr_bus_wr_en(mdr_bus_wr_en),
        .reg_wr_en(reg_wr_en),
        .reg_rd_addr(reg_rd_addr),
        .reg_wr_addr(reg_wr_addr),
        .alu_op(alu_op),
        .mem_read(mem_read),
        .mdr_mem_wr_en(mdr_mem_wr_en)
    );


    // External Memory connections

    assign mem_addr = mar_out;

    assign mem_data_out = mdr_out;

    assign mem_write = 1'b0; // Temporarily hardcoded to zero until STORE instruction is implemented
endmodule
