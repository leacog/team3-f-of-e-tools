module top();
	reg clk = 0;

	reg[31:0] input1;
	reg[31:0] input2;
	wire[31:0] data_out;

	DSPadder adder_inst(
		.input1(input1),
		.input2(input2),
		.out(data_out)
	);

//simulation
always
 #0.5 clk = ~clk;

initial begin
	$dumpfile ("DSPadder.vcd");
 	$dumpvars;

 	input1 = 32'h2710;
 	input2 = 32'h6f;

 	#1

 	input1 = 32'd0;
 	input2 = 32'd10;

 	#1

 	input1 = 32'd1000;
 	input2 = 32'd10;

 	#1

	input1 = 32'h0ffff;
 	input2 = 32'habd0000;

 	#1
	input1 = 32'h0001;
 	input2 = 32'hffff;

 	#1
	
	input1 = 32'hffff;
 	input2 = 32'hffff;

 	#1
	
	input1 = 32'haf0000;
 	input2 = 32'hafd0000;

 	#1

 	$finish;
end

endmodule
