module cla_adder(
  input logic [7:0] a,b,
  input logic cin,
  output logic [7:0] sum,
  output logic P,G
);
  
  logic [7:0] p,g;
  logic [8:0] c;
  
  always_comb begin
    g = a & b;
    p = a ^ b;
    
    c[0] = cin;
    for (int i = 0; i < 8; i++) begin
      c[i+1] = g[i] | (p[i] & c[i]);
    end
    
    sum = p ^ c[7:0];
    
    P = &p;
    
    G = g[7];
    for (int i = 6; i >= 0; i--) begin
      logic temp_p;
      temp_p = 1'b1;
      for (int j = 7; j > i; j--) begin
        temp_p &= p[j];
      end
      G |= (temp_p & g[i]);
    
  end
  end
endmodule
  
  
  
  
    
    