# Simulation of the whole processor
All the relevant bits are in `cpu/`. See the README there for more details.
The reason this git repo is one level up from the actual simulation code is that the processor verilog files reference the path `../include/`, and it has to be relative to where the simulation is being compiled (ie, `cpu/`).
