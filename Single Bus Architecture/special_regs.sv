module special_regs #(
    parameter int WIDTH = 16
)(
    input logic clk,
    input logic rst_n, // Active-low reset

    // Data inputs
    input logic [WIDTH-1:0] bus_in, // Main shared bus
    input logic [WIDTH-1:0] mem_data_in, // External memory input bus
    input logic [WIDTH-1:0] alu_result, // Output from ALU

    // Write enabling control signals
    input logic pc_wr_en, // Load PC from bus
    input logic ir_wr_en, // Load IR from bus
    input logic mar_wr_en, // Load MAR from bus
    input logic y_wr_en, // Load Y from bus 
    input logic z_wr_en, // Load Z from ALU result
    input logic mdr_bus_wr_en, // Load MDR from internal bus
    input logic mdr_mem_wr_en // Load MDR from external memory

    // Register Outputs

    output logic [WIDTH-1:0] pc_out, // To bus multiplexer
    output logic [WIDTH-1:0] ir_out, // To control unit decoder 
    output logic [WIDTH-1:0] mar_out, // To external address memory
    output logic [WIDTH-1:0] y_out, // To ALU input A
    output logic [WIDTH-1:0] z_out, // To bus multiplexer
    output logic [WIDTH-1:0] mdr_out // To bus multiplexer and external memory 
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Resetting all registers to 0 (PC resets to 0x0000)
            pc_out <= 0;
            ir_out <= 0;
            mar_out <= 0;
            y_out <= 0;
            z_out <= 0;
            mdr_out <= 0;
        end else begin
            // Registers directly loading from the shared bus
            if (pc_wr_en) pc_out <= bus_in;
            if (ir_wr_en) ir_out <= bus_in;
            if (mar_wr_en) mar_out <= bus_in;
            if (y_wr_en) y_out <= bus_in;

            // Z register loads data from ALU output, hence this loading doesn't depend on the main bus
            if (z_wr_en) z_out <= alu_result;

            // MDR loads two ways from external memory or from the main bus
            if (mdr_bus_wr_en) begin
                mdr_out <= bus_in;
            end else if (mdr_mem_wr_en) begin
                mdr_out <= mem_data_in;
            end
        end
    end
endmodule