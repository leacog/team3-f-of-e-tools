rm DSPalu
rm DSPalu.vcd

iverilog -o DSPalu ../../sail-core/verilog/DSPalu.v DSPalu_sim.v ../../sail-core/verilog/DSPadder.v ../../sail-core/verilog/DSPsubtractor.v ../../sail-core/verilog/alu_control.v SB_MAC16.v
./DSPalu
