module leading_zero_detector (
  input logic [23:0] in,
  output logic [4:0] count,
  output logic valid
);
  
  always_comb begin
    
    count = 5'd0;
    valid = 1'b1;
    
    // Priority Encoder
    casex (in)
      24'b1xxxxxxxxxxxxxxxxxxxxxxx: count = 5'd0;
      24'b01xxxxxxxxxxxxxxxxxxxxxx: count = 5'd1;
      24'b001xxxxxxxxxxxxxxxxxxxxx: count = 5'd2;
      24'b0001xxxxxxxxxxxxxxxxxxxx: count = 5'd3;
      24'b00001xxxxxxxxxxxxxxxxxxx: count = 5'd4;
      24'b000001xxxxxxxxxxxxxxxxxx: count = 5'd5;
      24'b0000001xxxxxxxxxxxxxxxxx: count = 5'd6;
      24'b00000001xxxxxxxxxxxxxxxx: count = 5'd7;
      24'b000000001xxxxxxxxxxxxxxx: count = 5'd8;
      24'b0000000001xxxxxxxxxxxxxx: count = 5'd9;
      24'b00000000001xxxxxxxxxxxxx: count = 5'd10;
      24'b000000000001xxxxxxxxxxxx: count = 5'd11;
      24'b0000000000001xxxxxxxxxxx: count = 5'd12;
      24'b00000000000001xxxxxxxxxx: count = 5'd13;
      24'b000000000000001xxxxxxxxx: count = 5'd14;
      24'b0000000000000001xxxxxxxx: count = 5'd15;
      24'b00000000000000001xxxxxxx: count = 5'd16;
      24'b000000000000000001xxxxxx: count = 5'd17;
      24'b0000000000000000001xxxxx: count = 5'd18;
      24'b00000000000000000001xxxx: count = 5'd19;
      24'b000000000000000000001xxx: count = 5'd20;
      24'b0000000000000000000001xx: count = 5'd21;
      24'b00000000000000000000001x: count = 5'd22;
      24'b000000000000000000000001: count = 5'd23;
      
      default: begin
        count = 5'd0;
        valid = 1'b0;
      end
    endcase
  end
endmodule