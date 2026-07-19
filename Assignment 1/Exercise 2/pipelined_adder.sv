module pipelined_adder(
  input logic clk,
  input logic [31:0] a,
  input logic [31:0] b,
  input logic cin,
  output logic [31:0] sum,
  output logic cout
);
  
  // Registers to hold bits when stages of the addition are being completed
  logic [23:0] a_reg1, b_reg1;
  logic [15:0] a_reg2, b_reg2;
  logic [7:0] a_reg3, b_reg3;
  
  // Registers to hold the finished sum while the rest of the sum is produced
  logic [7:0] sum_reg1;
  logic [15:0] sum_reg2;
  logic [23:0] sum_reg3;
  logic c1, c2, c3;
  
  // Wires
  logic [7:0] s0, s1, s2, s3;
  logic co0, c01, c02, c03;
  
  // Instantiating adders from the basic 8 bit adder
  bit_adder add0 (.a(a[7:0]), .b(b[7:0]), .cin(cin), .sum(s0), .cout(co0));
  bit_adder add1 (.a(a_reg1[7:0]), .b(b_reg1[7:0]), .cin(c1), .sum(s1), .cout(co1));
  bit_adder add2 (.a(a_reg2[7:0]), .b(b_reg2[7:0]), .cin(c2), .sum(s2), .cout(co2));
  bit_adder add3 (.a(a_reg3), .b(b_reg3), .cin(c3), .sum(s3), .cout(co3));
  
  always_ff @(posedge clk) begin
    // First Stage of the pipeline
    c1 <= co0;
    sum_reg1 <= s0;
    // The last 24 bits are being saved for the next stage
    a_reg1 <= a[31:8];
    b_reg1 <= b[31:8];
    
    // Second stage of the pipeline
    c2 <= co1;
    sum_reg2 <= {s1, sum_reg1};
    // The last 16 bits are being saved for the next stage
    a_reg2 <= a_reg1[23:8];
    b_reg2 <= b_reg1[23:8];
    
    // Third stage of the pipeline
    c3 <= co2;
    sum_reg3 <= {s2, sum_reg2};
    // The last 8 bits are being saved for the next stage
    a_reg3 <= a_reg2[15:8];
    b_reg3 <= b_reg2[15:8];
    
    
    cout <= co3;
    sum <= {s3, sum_reg3};
  end 
endmodule