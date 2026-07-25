// Hardwiring Register 0 to zero
module reg_file #(
    parameter int WIDTH = 16,
    parameter int REG_COUNT = 8
)(
    input logic clk, // Clock
    input logic rst_n, // Active low reset

    // Writing Interface
    input logic wr_en, // Enable signal for writing
    input logic [2:0] wr_addr, // 3 bit address to select registers to write to (R0 - R7)
    input logic [WIDTH-1:0] wr_data, // 16-bit data to write

    // Reading Interface
    input logic [2:0] rd_addr, // 3 bit address to select registers to read from (R0 - R7)
    output logic [WIDTH-1:0] rd_data // 16-bit data output
);


    // Array of 8 registers, each 16 bits wide
    logic [WIDTH-1:0] registers [0:REG_COUNT-1]; // Packed Array goes [high:low] , Unpacked array goes [low:high]

    // Synchronous write operation (Writing requires synchronous while Reading doesn't)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Clear registers on reset
            for (int i = 0; i < REG_COUNT; i++) begin
                registers[i] <= '0;
            end
        end else if (wr_en) begin // Start writing on enable
            // Prevent writing to hardwired R0
            if (wr_addr != 3'b000) begin
                registers[wr_addr] <= wr_data;
            end
        end
    end

    // Combinational Read Operation
    always_comb begin
        if (rd_addr == 3'b000) begin
            rd_data = '0;
        end else begin
            rd_data = registers[rd_addr];
        end
    end
endmodule
