module n_adder #(
    parameter N = 8 // Parametrized module
)(
    input logic signed [N-1:0] A, B, // Signed, little-endian, packed
    input logic ci,
    output logic signed [N-1:0] S,
    output logic co
);
    logic C [N:0]; // little-endian, unpacked
    assign C[0] = ci;
    assign co = C[N];

    genvar i; // Generating instances 
    for (i = 0; i < N; i = i+1) begin: add

        full_adder fa (
            .a(A[i]),
            .b(B[i]),
            .ci(C[i]), // Chaining
            .co(C[i+1]),
            .sum(S[i])
        );
    end
endmodule