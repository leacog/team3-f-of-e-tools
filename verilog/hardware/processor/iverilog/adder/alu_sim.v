`define FUNC 4'b111

module top();
	reg clk = 0;

	reg[31:0] A, B;
	wire[31:0] ALUOut;
	wire Branch_Enable;

	//alu_control interface
	reg[3:0] FuncCode;
	reg[6:0] Opcode;

	//alu aluctl interface
	wire[6:0] AluCtl_wire;

	ALUControl aluCtrl_inst(
		.FuncCode(FuncCode),
		.ALUCtl(AluCtl_wire),
		.Opcode(Opcode)
	);

	alu alu_inst(
		.ALUctl(AluCtl_wire),
		.A(A),
		.B(B),
		.ALUOut(ALUOut),
		.Branch_Enable(Branch_Enable)
	);

//simulation
always
 #0.5 clk = ~clk;

initial begin
	$dumpfile ("alu.vcd");
 	$dumpvars;

 	//reg[31:0] A, B;
 	//reg[3:0] FuncCode; //bit 32 + bit 14:12
	//reg[6:0] Opcode; //bits 6:0

 	A = 32'b0;
 	B = 32'b0;
 	FuncCode = `FUNC;
 	Opcode = 7'b0;

 	#5
 	//simulate SLT instuction
 	A = 32'b0;
 	B = 32'b10;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

 	#5

	//simulate SLT instuction
 	A = 32'b1001;
 	B = 32'b1001;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

	#5
	
	//simulate SLT instuction
 	A = 32'b11;
 	B = 32'b10;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

 	#5
	//simulate SLT instuction
 	A = 32'hf3;
 	B = 32'hf2;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

 	#5

	//simulate SLT instuction
 	A = 32'hf3;
 	B = 32'hf3;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

 	#5

	//simulate SLT instuction
 	A = 32'hf3;
 	B = 32'hf4;
 	FuncCode = `FUNC;
 	Opcode = 7'b1100011;

 	#5


 	$finish;
end

endmodule
