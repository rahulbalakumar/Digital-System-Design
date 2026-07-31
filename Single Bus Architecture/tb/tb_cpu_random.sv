class cpu_transaction;
    rand logic [3:0] opcode;
    rand logic [15:0] data_val1;
    rand logic [15:0] data_val2;

    // Constraints to ensure valid instructions and to test edge cases
    constraint valid_ops {
        opcode inside {4'h1, 4'h2};
    }
endclass


`timescale 1ns / 1ps

module tb_cpu_random;

    parameter int WIDTH = 16;


    logic clk;
    logic rst_n;
    logic [WIDTH-1:0] mem_addr;
    logic mem_read;
    logic mem_write;
    logic [WIDTH-1:0] mem_data_in;
    logic [WIDTH-1:0] mem_data_out;

    initial clk = 0;
    always #5 clk = ~clk;

    logic [15:0] ram [0:255];

    assign mem_data_in = mem_read ? ram[mem_addr[7:0]] : 16'h0000;

    cpu #(
        .WIDTH(WIDTH)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .mem_addr(mem_addr),
        .mem_read(mem_read),
        .mem_write(mem_write),
        .mem_data_in(mem_data_in),
        .mem_data_out(mem_data_out)
    );

    initial begin
        cpu_transaction tx;
        int error_count = 0;
        int num_tests = 50;

        tx = new();


        $display("----------------------------------");
        $display(" STARTING CONSTRAINED-RANDOM TEST ");
        $display("----------------------------------");

        for (int i = 0; i < num_tests; i++) begin

            rst_n = 0;
            #20;
            rst_n = 1;

            if (!tx.randomize()) begin
                $error("Randomization failed at iteration %0d", i);
                $finish;
            end

            for (int j = 0; j < 256; j++) ram[j] = 0; // Erasing RAM

            ram[10] = tx.data_val1; // Pointers in RAM
            ram[11] = tx.data_val2;
            dut.u_reg_file.registers[5] = 16'd10;
            dut.u_reg_file.registers[6] = 16'd11;

            if (tx.opcode == 4'h2) begin
                // LOAD INSTRUCTION FORMAT : [OPCODE(4)][Rd(3)][Rs1(3)][Unused(6)]
                ram[0] = {4'h2, 3'd1, 3'd5, 6'b000000};
                ram[1] = 16'h0000; // NOP
                ram[2] = 16'h0000;

                repeat (20) @(posedge clk);

            end else if (tx.opcode == 4'h1) begin
                // ADD INSTRUCTION FORMAT : [OPCODE(4)][Rd(3)][Rs1(3)][Rs2(3)][Unused(3)]
                ram[0] = {4'h2, 3'd1, 3'd5, 6'b000000}; // LOAD R1 from the memory address found in R5
                ram[1] = {4'h2, 3'd2, 3'd6, 6'b000000}; // LOAD R2 from the memory address found in R6
                ram[2] = {4'h1, 3'd3, 3'd1, 3'd2, 3'b000}; // ADD R1 and R2 then put the result in R3

                repeat (40) @(posedge clk);
            end

            #200;

            if (tx.opcode == 4'h2) begin
                if(dut.u_reg_file.registers[1] !== tx.data_val1) begin
                    $error("[FAIL] LOAD: Expected %0h, Got %0h", tx.data_val1, dut.u_reg_file.registers[1]);
                    error_count++;
                end
        
            end else if (tx.opcode == 4'h1) begin
                logic [WIDTH-1:0] expected_sum = tx.data_val1 + tx.data_val2;
                if (dut.u_reg_file.registers[3] !== expected_sum) begin
                    $error("[FAIL] ADD: Expected %0h + %0h = %0h, Got %0h",
                            tx.data_val1, tx.data_val2, expected_sum, dut.u_reg_file.registers[3]);
                    error_count++;
                end
            end
        end

        $display("---------------------------------");
        if (error_count == 0)
            $display("RANDOM VERIFICATION PASSED (%0d TESTS)!", num_tests);
        else
            $display("RANDOM VERIFICATION FAILED with %0d errors.", error_count);
        $display("---------------------------------");
        $finish;
    end
endmodule