module top();
	reg clk = 0;

	reg[31:0] addr;
	wire[31:0] out;

	instruction_memory insmem(
		.addr(addr),
		.out(out)
	);


//simulation
always
 #0.5 clk = ~clk;

initial begin
	$dumpfile ("insmem.vcd");
 	$dumpvars;

 	//reg[31:0] A, B;
 	//reg[3:0] FuncCode; //bit 32 + bit 14:12
	//reg[6:0] Opcode; //bits 6:0

 	addr = 32'b0;

 	#5
 	
	addr = 32'h4;

	#5
	addr = 32'h8;

	#5
	addr = 32'hc;

	#5
	addr = 32'h10;

	#5
	addr = 32'h14;

	#5

 	$finish;
end

endmodule
