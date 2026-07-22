module full_adder_(
    input logic a, b, ci,
    output logic sum, co
);
    assign {co, sum} = a + b + ci;
endmodule

module n_adder #(
    parameter N = 4
)(
    input logic signed[N-1:0] A, B,
    input logic ci,
    output logic signed[N-1:0] S,
    output logic co
);
    assign {co, S} = A + B + ci;
endmodule