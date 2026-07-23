always_latch // Latch
    if (en) y <= x;


always_ff @(posedge clk) // Flip-flop or Register
    y <= x;


always_ff @(posedge clk or negedge rstn) // Register with active low, asynchronous reset 
    if (!rstn) y <= '0;
    else y <= x;

always_ff @(posedge clk)    // Resgister with active high, synchronous reset
    if (rst) y <= '0;
    else y <= x;    

always_ff @(posedge clk or negedge rstn) // Register with clock enable
    if (!rstn) y <= '0;
    else if (en) y <= x;