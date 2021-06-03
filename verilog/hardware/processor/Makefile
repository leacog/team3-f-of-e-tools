#Uncomment mod-version to include
MODS = allDSP_INSMEM
#MODS = allDSP
#MODS = ALUadder
#MODS = ALUcomparator
#MODS = ALUsubtractor
#MODS = ALUaddsub
#MODS = CPUadder
#MODS = INSMEM
#MODS = baseline

USE_SUBSET = _s.v
#USE_SUBSET = .v

DESIGN	= sail
VERSION = 03-06_bsort

sail-nextpnr:
	cp mods_includes/$(MODS)$(USE_SUBSET) sail-core/include/mods_to_use.v
	cp programs/data.hex verilog/
	cp programs/program.hex verilog/
	yosys -q ../../../yscripts/$(DESIGN).ys -l logfiles/yosys_$(MODS)_$(VERSION)$(USE_SUBSET).log
	nextpnr-ice40 --up5k --package uwg30 --json $(DESIGN).json --pcf pcf/$(DESIGN).pcf --asc $(DESIGN).asc -l logfiles/nextpnr_$(MODS)_$(VERSION)$(USE_SUBSET).log
	icetime -p pcf/$(DESIGN).pcf -P uwg30 -d up5k -t $(DESIGN).asc
	icepack $(DESIGN).asc bitstreams/$(MODS)_$(VERSION)$(USE_SUBSET).bin

clean:
	rm -f *.json *.blif *.asc *.bin
