module cla_32bit(
  input  logic [31:0] a, b,
  input  logic        cin,
  output logic [31:0] sum,
  output logic        cout
);
  
  logic [3:0] P, G;
  logic [4:0] C;
  
  assign C[0] = cin;
  
  
  cla_adder cla0 (.a(a[7:0]),   .b(b[7:0]),   .cin(C[0]), .sum(sum[7:0]),   .P(P[0]), .G(G[0]));
  cla_adder cla1 (.a(a[15:8]),  .b(b[15:8]),  .cin(C[1]), .sum(sum[15:8]),  .P(P[1]), .G(G[1]));
  cla_adder cla2 (.a(a[23:16]), .b(b[23:16]), .cin(C[2]), .sum(sum[23:16]), .P(P[2]), .G(G[2]));
  cla_adder cla3 (.a(a[31:24]), .b(b[31:24]), .cin(C[3]), .sum(sum[31:24]), .P(P[3]), .G(G[3]));

  
  assign C[1] = G[0] | (P[0] & C[0]);
  assign C[2] = G[1] | (P[1] & G[0]) | (P[1] & P[0] & C[0]);
  assign C[3] = G[2] | (P[2] & G[1]) | (P[2] & P[1] & G[0]) | (P[2] & P[1] & P[0] & C[0]);
  assign C[4] = G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]) | (P[3] & P[2] & P[1] & P[0] & C[0]);
  
  assign cout = C[4];

endmodule