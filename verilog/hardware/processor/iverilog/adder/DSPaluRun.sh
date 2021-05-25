rm DSPalu
rm DSPalu.vcd

iverilog -o DSPalu DSP_alu.v DSPalu_sim.v DSPadder.v DSPsubtractor.v alu_control.v SB_MAC16.v
./DSPalu
