module adder (
  input logic [31:0] a, b,
  output logic [31:0] sum
);
  
  logic s_a, s_b; // Sign
  logic [7:0] e_a, e_b; // Exponent
  logic [23:0] m_a, m_b; // Mantissa
  
  // Alignment
  logic [7:0] common_exp;
  logic [23:0] aligned_m_a, aligned_m_b;
  
  logic res_sign;
  logic [24:0] res_mant;
  
  
  logic [7:0] final_exp;
  logic [22:0] final_mant;
  
  unpack u_a (.float_in(a), .sign(s_a), .exponent(e_a), .mantissa(m_a), .flag());
  unpack u_ab (.float_in(b), .sign(s_b), .exponent(e_b), .mantissa(m_b), .flag());
  
  align alignment (
    .exp_a(e_a), .exp_b(e_b),
    .mant_a(m_a), .mant_b(m_b),
    .final_exp(common_exp),
    .shifted_mant_a(aligned_m_a), .shifted_mant_b(aligned_m_b)
  );
  
  mantissa_adder adder (
    .sign_a(s_a), .sign_b(s_b),
    .mant_a(aligned_m_a), .mant_b(aligned_m_b),
    .res_sign(res_sign), .res_mant(res_mant)
  );
  
  normalization norm(
    .exp_in(common_exp),
    .mant_in(res_mant),
    .exp_out(final_exp),
    .mant_out(final_mant)
  );
  
  assign sum = {res_sign, final_exp, final_mant};
endmodule