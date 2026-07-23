module counter #(parameter N = 8)
(
    input logic clk, rst, incr,
    output logic [N-1:0] count_reg
);

    always_ff @(posedge clk) begin // A flip-flop sensitive to clk's positive edge

        if (rst) count_reg <= 0; // <= is blocking assignment
        else if (incr) count_reg + 1'b1;
    end
endmodule