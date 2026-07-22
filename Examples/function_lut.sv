module function_lut #(
    parameter W_X = 4, W_Y = 8,
    parameter signed A = 1, B = 10, C = -10
)(
    input logic signed [W_X-1:0] xf, xq,
    input logic signed [W_Y-1:0]yiq,
    output logic signed [W_Y-1:0] yf, yq_lut, yq_fun,
    output logic signed [W_X-1:0] xiq
);

    function automatic [W_Y-1:0] factorial( // automatic -> synthesizable
        input logic [W_X-1:0] n);
        factorial = (n==1 || n==0) ? 1 : n * factorial(n-1); // Outdated method where output is given to the function's name (recursion can be used as well)
    endfunction

    function automatic signed [W_Y-1:0] quadratic(
        input logic signed [W_X-1:0] x);
        return A * x**2 + B * x + C; // Modern method similar to programming languages where return is used
    endfunction

    function automatic signed [W_X-1:0] inverse_quadratic(
        input logic signed [W_Y-1:0] y);
        logic signed [W_Y-1:0] result, quad;
        int error, min_error = 2**W_Y;

        for (int ux = 0; ux < 2**W_X; ux++) begin
            logic signed [W_X-1:0] x = ux;
            quad = quadratic(x);

            error = (y - quad);
            error = error > 0 ? error : -error;
        
            if (error < min_error) begin
                min_error = error;
                result = x;
            end
        end
        return result;
    endfunction

    genvar i;
    logic signed [2**W_X-1:0][W_Y-1:0] lut_factorial;
    logic signed [2**W_X-1:0][W_Y-1:0] lut_quadratic; // Here these are arrays and they are packed; These are LUTs
    logic signed [2**W_Y-1:0][W_X-1:0] lut_inverse_quadratic;

    for (i = 0; i < 2**W_X; i=i+1)
        assign lut_quadratic[i] = quadratic(i);

    for (i = 0; i < 2**W_Y; i = i+1)
        assign lut_inverse_quadratic[i] = inverse_quadratic(i);

    assign yf = lut_factorial[xf];
    assign xiq = lut_inverse_quadratic[yiq];
    assign yq_lut = lut_quadratic[xq]; // Multiplexers to read LUT values

    assign yq_fun = quadratic(xq); // Here the circuit is synthesized, combinational circuit and not LUT
endmodule

