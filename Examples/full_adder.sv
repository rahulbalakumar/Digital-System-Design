module full_adder(
    input logic a, b, ci,
    output logic sum, co
);

    logic wire_1, wire_2;

    // Method 1
    assign wire_1 = a ^ b;
    assign wire_2 = wire_1 & ci;

    // Method 2
    wire wire_3 = a & b;

    // Method 3
    always_comb begin
        co = wire_2 | wire_3;
        sum = wire_1 ^ ci;
    end
endmodule