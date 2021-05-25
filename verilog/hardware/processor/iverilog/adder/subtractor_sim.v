module top();
	reg clk = 0;

	reg[31:0] input1;
	reg[31:0] input2;
	wire[31:0] data_out;

	subtractor adder_inst(
		.input1(input1),
		.input2(input2),
		.out(data_out)
	);

//simulation
always
 #0.5 clk = ~clk;

initial begin
	$dumpfile ("subtractor.vcd");
 	$dumpvars;

 	input1 = 32'd0;
 	input2 = 32'd0;

 	#1

 	input1 = 32'd10;
 	input2 = 32'd9;

 	#1

 	input1 = 32'd4000;
 	input2 = 32'd1000;

 	#1

 	input1 = 32'd65536;
 	input2 = 32'd65540;

 	#1

 	input1 = 32'd1265536;
 	input2 = 32'd65540;

 	#1

 	input1 = 32'd10;
 	input2 = 32'd11;

	#1

 	input1 = 32'd256;
 	input2 = 32'd65540;

	#1
 	
	 
	$finish;
end

endmodule
