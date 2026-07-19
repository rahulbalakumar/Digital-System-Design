module align (
    input  logic [7:0]  exp_a, exp_b,
    input  logic [23:0] mant_a, mant_b,
    output logic [7:0]  final_exp,
    output logic [23:0] shifted_mant_a, shifted_mant_b
);
    logic [7:0] diff;
    logic a_is_smaller;

    always_comb begin
        if (exp_a < exp_b) begin
            a_is_smaller = 1'b1;
            diff = exp_b - exp_a;
            final_exp = exp_b;
            
            // Shift Mantissa A to the right
            shifted_mant_a = mant_a >> diff;
            shifted_mant_b = mant_b;
        end else begin
            a_is_smaller = 1'b0;
            diff = exp_a - exp_b;
            final_exp = exp_a;
            
            // Shift Mantissa B to the right
            shifted_mant_a = mant_a;
            shifted_mant_b = mant_b >> diff;
        end
    end
endmodule