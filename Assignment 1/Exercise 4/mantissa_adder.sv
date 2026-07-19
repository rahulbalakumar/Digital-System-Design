module mantissa_adder (
    input  logic        sign_a, sign_b,
    input  logic [23:0] mant_a, mant_b,
    output logic        res_sign,
    output logic [24:0] res_mant 
);

    logic [23:0] op_a, op_b;
    logic        effective_sub;

    always_comb begin
        
        effective_sub = sign_a ^ sign_b; // Determining if Addition or Subtraction

        if (effective_sub) begin
            
            if (mant_a >= mant_b) begin
                res_sign = sign_a;
                res_mant = {1'b0, mant_a} - {1'b0, mant_b};
            end else begin
                res_sign = sign_b;
                res_mant = {1'b0, mant_b} - {1'b0, mant_a};
            end
        end else begin
            res_sign = sign_a;
            res_mant = {1'b0, mant_a} + {1'b0, mant_b};
        end
    end
endmodule