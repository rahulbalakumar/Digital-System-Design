// Class
class Random_Sel; // Random Attribute
    rand bit [2:0] num;
    constraint c {num inside {[0:4]};} // Constraints for randomization

    function new();         // Optional Constructor
        this.num = 3'd4;
    endfunction
endclass

class Random_Num #(WIDTH = 8);
    rand bit signed [WIDTH-1:0] num; // bit represents 2 state logic {0,1} without X-Unknown,Z-High Impedance
endclass

module alu_tb;
    timeunit 1ns/1ps;

    localparam WIDTH = 8;
    logic [2:0] sel;
    logic signed [WIDTH-1:0] bus_a, bus_b, alu_out;
    logic Z;

    alu #(.WIDTH(WIDTH)) dut (.*);

    Random_Num #(.WIDTH(WIDTH)) A_r = new(), B_r = new(); // Object handle (pointer)
    Random_Sel sel_r = new(); // Randomized at construction , custom constructor

    initial begin
        $dumpfile("dump.vcd"); $dumpvars(0, dut);

        repeat(5) begin
            #10
            bus_a <= A_r.num; bus_b <= B_r.num; sel <= sel_r.num; // Accessing an attribute
            A_r.randomize();
            B_r.randomize(); // Randomizing rand, randc attributes as per constratints
            sel_r.randomize();
        end

        #30 bus_a <= 8'd5; bus_b <= 8'd10; sel <= 3'b000;
        #10 bus_a <= 8'd30; bus_b <= -8'd10; sel <= 3'b001;
        #10 bus_a <= 8'd5; bus_b <= 8'd10; sel <= 3'b010;
        #10 bus_a <= 8'd51; bus_b <= 8'd17; sel <= 3'b011;
    end 
endmodule
