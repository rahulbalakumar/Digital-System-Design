module fir_filter #(
    parameter N = 5, W_X = 8, W_K = 3,
    parameter logic signed [W_K-1:0] K [N + 1] = {1,2,3,4,5,6},
    localparam W_Y = W_X + W_K + $clog2(N+1)
)(
    input clk, rstn,
    input logic signed [W_X-1:0] x,
    output logic signed [W_Y-1:0] y
);

    genvar n;
    logic signed [N:0][W_X-1:0]  z;

    assign z[0] = x;
    always_ff @(posedge clk or negedge rstn)
        z[N:1] <= !rstn ? '0 : z[N-1:0];

    always_comb begin
        y = 0;
        for (int n = 0; n < N+1; n=n+1)
            y = y + K[n] * $signed(z[n]);
    end
endmodule