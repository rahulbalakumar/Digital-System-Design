module full_adder_tb; // No need for inputs / outputs

    timeunit 10ns; timeprecision 1ns; // Time units

    logic a = 0, ci = 0, b, sum, co; // Variable declaration with / without initial values

    full_adder dut (.*); // Module Instantiation (Dot-Star way)

    initial begin // Simulation starts
        $dumpfile("dump.vcd"); $dumpvars(0,dut); // Dump waveforms
        
        #30 a <= 0; b <= 0; ci <= 0;
        #10 a <= 0; b <= 0; ci <= 1; // Delay / wait and drive input pins

        #20 a <= 1; b <= 1; ci <= 0;

        #1 assert ({co, sum} == a+b+ci) // Assertion
            $display ("OK"); // Pass statement
                else $error("Not OK"); // Fail statement
        
        #10 a <= 1; b <= 1; ci <= 1;

        #1 assert (dut.wire_1 == 0) // 1 (xor) 1 = 0
              else $error("False. wire_1: %d", dut.wire_1);
        $finish();
    end
endmodule