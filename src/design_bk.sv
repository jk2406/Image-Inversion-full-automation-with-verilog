module  invert #(
    parameter string IN_FILE  = "test.hex",
    parameter string OUT_FILE = "output.hex",
    parameter int WIDTH =          610,
    parameter int HEIGHT = 874
);
    localparam int PIXELS = WIDTH * HEIGHT;
    localparam int MEM_DEPTH = PIXELS * 3; // 3 bytes per pixel (R,G,B)
    byte mem [0:MEM_DEPTH-1];      // input RGB hex
    byte out [0:MEM_DEPTH-1];      // inverted output
    integer fd;
    integer i;
    initial begin
        // -----------------------------
        // Read input hex file
        // -----------------------------
        $readmemh(IN_FILE, mem);
        // -----------------------------
        // Invert colors
        // -----------------------------
        for(i = 0; i < MEM_DEPTH; i = i + 1) begin
            out[i] = ~mem[i]; // invert all 8-bit values
        end
        // -----------------------------
        // Write output hex file
        // -----------------------------
        fd = $fopen(OUT_FILE, "w");
        if(fd == 0) begin
            $display("Cannot create output hex file!");
            $finish;
        end
        for(i = 0; i < MEM_DEPTH; i = i + 1) begin
            $fwrite(fd, "%02h\n", out[i]); // one hex byte per line
        end
        $fclose(fd);
        $display("Inverted hex written to %s", OUT_FILE);
        $finish;
    end
endmodule
