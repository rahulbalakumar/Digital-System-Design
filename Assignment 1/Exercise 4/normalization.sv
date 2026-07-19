module normalization (
  input logic [7:0] exp_in,
  input logic [24:0] mant_in,
  output logic [7:0] exp_out,
  output logic [22:0] mant_out
);
  
  
  logic [4:0] lzd_count;
  logic [24:0] shifted_mant;
  logic overflow;
  
  leading_zero_detector lzd (.in(mant_in[23:0]), .count(lzd_count), .valid());
  
  always_comb begin
    
    overflow = mant_in[24];
    
    if (overflow) begin
      
      shifted_mant = mant_in >> 1;
      exp_out = exp_in + 1'b1;
    end else begin
      shifted_mant = mant_in << lzd_count;
      exp_out = exp_in - lzd_count;
    end
    
    mant_out = shifted_mant[22:0];
  end
endmodule
  