`timescale 1ns / 1ps

module tb_cpu_scoreboard;

    parameter int WIDTH = 16;

    logic clk;
    logic rst_n;
    logic [WIDTH-1:0] mem_addr;
    logic mem_read;
    logic mem_write;
    logic [WIDTH-1:0] mem_data_in;
    logic [WIDTH-1:0] mem_data_out;

    // Initiating Clock
    initial clk = 0;
    always #5 clk = ~clk;


    // RAM Array (256 x 16 bit)
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
        logic [15:0] expected_r1;
        logic [15:0] expected_r2;
        logic [15:0] expected_r3;
        int errors = 0;

        rst_n = 0;

        for (int i = 0; i < 256; i++) begin
            ram[i] = 16'h0000;
        end

        ram[0] = 16'h2340; // Instruction 1: LOAD R1, [R5]
        ram[1] = 16'h2580; // Instruction 2: LOAD R2, [R6]
        ram[2] = 16'h1650; // Instruction 3: ADD R3, R1, R2

        ram[10] = 16'd120; // Loading 120 to add
        ram[11] = 16'd130; // Loading 130 to add


        #20;
        rst_n = 1;
        #1;

        dut.u_reg_file.registers[5] = 16'd10; // Hardcoding memory's location
        dut.u_reg_file.registers[6] = 16'd11;

        #1000

        $display("---------------------------");
        $display("  RUNNING CPU SCOREBOARD   ");
        $display("---------------------------");

        expected_r1 = ram[10];
        expected_r2 = ram[11];
        expected_r3 = expected_r1 + expected_r2;

        // Checking R1 loading instruction
        if (dut.u_reg_file.registers[1] == expected_r1) begin
            $display("[PASS] R1 check: Expected = %0d, Actual = %0d", expected_r1, dut.u_reg_file.registers[1]);
        end else begin
            $error("[FAIL] R1 check : Expected = %0d, Actual = %0d", expected_r1, dut.u_reg_file.registers[1]);
            errors = errors + 1;
        end

        // Checking R2 loading instruction
        if (dut.u_reg_file.registers[2] == expected_r2) begin
            $display("[PASS] R2 check: Expected = %0d, Actual = %0d", expected_r2, dut.u_reg_file.registers[2]);
        end else begin
            $error("[FAIL] R2 check : Expected = %0d, Actual = %0d", expected_r2, dut.u_reg_file.registers[2]);
            errors = errors + 1;
        end

        // Checking ADD instruction 
        if (dut.u_reg_file.registers[3] == expected_r3) begin
            $display("[PASS] R3 (ADD) check: Expected = %0d, Actual = %0d", expected_r3, dut.u_reg_file.registers[3]);
        end else begin
            $error("[FAIL] R3 (ADD) check : Expected = %0d, Actual = %0d", expected_r3, dut.u_reg_file.registers[3]);
            errors = errors + 1;
        end

        $display("------------------------------");
        if (errors == 0) begin
            $display("TESTBENCH STATUS: ALL TESTS PASSED!");
        end else begin
            $display("TESTBENCH STATUS: FAILED WITH %0d ERRORS!", errors);
        end
        $display("------------------------------");

        $finish;
    end
endmodule
