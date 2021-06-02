rm braminsmem
rm braminsmem.vcd

iverilog -o braminsmem ../../sail-core/verilog/instruction_mem.v braminsmem_sim.v
./braminsmem

rm braminsmem
