rm braminsmem
rm braminsmem.vcd

iverilog -o braminsmem ../../sail-core/verilog/instruction_mem_explicit.v braminsmem_sim.v ../../cpu-simulation/cpu/ice40-primitives/SB_RAM40_4K.v ../../sail-core/verilog/SB_RAM1024x4.v 
./braminsmem

rm braminsmem
