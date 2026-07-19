module unpack (
    input  logic [31:0] float_in,
    output logic        sign,
    output logic [7:0]  exponent,
    output logic [23:0] mantissa, 
    output logic        flag 
);

    always_comb begin
        sign     = float_in[31];
        exponent = float_in[30:23];
        
        
        if (exponent == 8'd0) begin
            mantissa = {1'b0, float_in[22:0]};
        end else begin
            mantissa = {1'b1, float_in[22:0]};
        end
        
        
        flag = (exponent == 8'd0 || exponent == 8'hFF);
    end

endmodule