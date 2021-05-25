rm DSPsubtractor
rm DSPsubtractor.vcd
iverilog -o DSPsubtractor DSPsubtractor.v DSPsubtractor_sim.v SB_MAC16.v
./DSPsubtractor
