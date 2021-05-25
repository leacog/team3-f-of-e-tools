rm alu
rm alu.vcd
iverilog -o alu alu.v alu_sim.v alu_control.v
./alu
