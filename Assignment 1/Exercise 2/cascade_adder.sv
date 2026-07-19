module cascade_adder(
  input logic [31:0] a,
  input logic [31:0] b,
  input logic cin,
  output logic [31:0] sum,
  output logic cout
);
  
  logic c1, c2, c3; // Wires used to connect each independant 8 bit adder blocks
  
  // Instantiating each individual 8 bit adder blocks
  bit_adder add0 (.a(a[7:0]),.b(b[7:0]),.cin(cin),.sum(sum[7:0]),.cout(c1));
  bit_adder add1 (.a(a[15:8]),.b(b[15:8]),.cin(c1),.sum(sum[15:8]),.cout(c2));
  bit_adder add2 (.a(a[23:16]),.b(b[23:16]),.cin(c2),.sum(sum[23:16]),.cout(c3));
  bit_adder add3 (.a(a[31:24]),.b(b[31:24]),.cin(c3),.sum(sum[31:24]),.cout(cout));
  
endmodule