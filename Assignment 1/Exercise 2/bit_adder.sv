// Basic 8 bit adder module to be instantiated later
module bit_adder(
  input logic [7:0] a,
  input logic [7:0] b,
  input logic cin,
  output logic [7:0] sum,
  output logic cout
);
  always_comb begin
    {cout,sum} = a + b + cin;
  end 
endmodule

