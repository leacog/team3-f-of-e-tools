rm DSPadder
rm DSPadder.vcd

iverilog -o DSPadder ../../sail-core/verilog/DSPadder.v DSPadder_sim.v SB_MAC16.v
./DSPadder
