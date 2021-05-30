rm insmem
rm insmem.vcd

iverilog -o insmem ../../sail-core/verilog/instruction_mem_bram2.v insmem_sim.v
./insmem

rm insmem
