#Uncomment mod-version to include
#MODS = allDSP_INSMEM
#MODS = allDSP
#MODS = ALUadder
#MODS = ALUcomparator
#MODS = ALUsubtractor
MODS = ALUaddsub
#MODS = CPUadder
#MODS = INSMEM
#MODS = baseline

DESIGN	= sail
VERSION = v0

sail-nextpnr:
	cp mods_includes/$(MODS).v sail-core/include/mods_to_use.v
	cp programs/data.hex verilog/
	cp programs/program.hex verilog/
	yosys -q ../../../yscripts/$(DESIGN).ys -l logfiles/yosys_$(MODS)_$(VERSION).log
	nextpnr-ice40 --up5k --package uwg30 --json $(DESIGN).json --pcf pcf/$(DESIGN).pcf --asc $(DESIGN).asc -l logfiles/nextpnr_$(MODS)_$(VERSION).log
	icetime -p pcf/$(DESIGN).pcf -P uwg30 -d up5k -t $(DESIGN).asc
	icepack $(DESIGN).asc $(DESIGN).bin

clean:
	rm -f *.json *.blif *.asc *.bin
