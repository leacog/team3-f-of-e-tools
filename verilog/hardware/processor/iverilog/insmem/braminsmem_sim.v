module top();
	reg clk = 0;

	reg[31:0] addr;
	wire[31:0] out;

	instruction_memory_bram insmem(
		.clk(clk),
		.addr(addr),
		.out(out)
	);


//simulation
always
 #0.5 clk = ~clk;

initial begin
	$dumpfile ("braminsmem.vcd");
 	$dumpvars;

 	//reg[31:0] A, B;
 	//reg[3:0] FuncCode; //bit 32 + bit 14:12
	//reg[6:0] Opcode; //bits 6:0

 	#0.3
	
	addr = 32'd1;
	
	#1
	
	addr = 32'b0;

 	#6
 	
	addr = 32'b1101101100;

	#6
	addr = 32'b11010110100;

	#6
	addr = 32'b100111100100;

	#6
	addr = 32'b111110110000;

	#6
	addr = 32'h14;

	#6


 	$finish;
end

endmodule
