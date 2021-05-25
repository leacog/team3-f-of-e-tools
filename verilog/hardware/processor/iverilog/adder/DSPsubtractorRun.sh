rm DSPsubtractor
rm DSPsubtractor.vcd
iverilog -o DSPsubtractor ../../sail-core/verilog/DSPsubtractor.v DSPsubtractor_sim.v SB_MAC16.v
./DSPsubtractor
