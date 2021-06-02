module top();
	reg clk = 1;

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

 	addr = 32'b0;

 	#6
 	
	addr = 32'h4;

	#6
	addr = 32'h8;

	#6
	addr = 32'hc;

	#6
	addr = 32'h10;

	#6
	addr = 32'h14;

	#6

 	$finish;
end

endmodule
