rm alu
rm alu.vcd
iverilog -o alu ../../verilog/alu.v alu_sim.v ../../verilog/alu_control.v ../../verilog/DSPsubtractor.v ../../verilog/DSPadder.v ../../cpu-simulation/cpu/ice40-primitives/SB_MAC16.v
./alu
