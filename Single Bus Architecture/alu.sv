module alu #(
    parameter int WIDTH = 16
)(
    input logic [WIDTH-1:0] a, // Input A from register Y
    input logic [WIDTH-1:0] b, // Input B from shared bus
    input logic [2:0] alu_op, // Select control signal
    output logic [WIDTH-1:0] result, // ALU output to register Z
    output logic zero // Zero flag
);


    // ALU Opcodes
    localparam ADD = 3'b000;
    localparam SUB = 3'b001;
    localparam AND = 3'b010;
    localparam OR = 3'b011;
    localparam NOT = 3'b100;
    localparam PASSB = 3'b101; // Passes Input B directly from the bus
    
    always_comb begin
        case (alu_op)
            ADD: result = a + b;
            SUB: result = a - b;
            AND: result = a & b;
            OR: result = a | b;
            NOT: result = ~b;
            PASSB: result = b;
            default: result = '0;
        endcase
    end

    assign zero = (result = '0);
endmodule