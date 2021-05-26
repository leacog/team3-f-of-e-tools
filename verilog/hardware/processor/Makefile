DESIGN	= sail_DSPalu
YOSYS_LOG = aluTony
NEXTPNR_LOG = aluTony

sail-nextpnr:
	cp programs/data.hex verilog/
	cp programs/program.hex verilog/
	yosys -q ../../../yscripts/$(DESIGN).ys -l yosysLog_$(YOSYS_LOG).log
	nextpnr-ice40 --up5k --package uwg30 --json $(DESIGN).json --pcf pcf/$(DESIGN).pcf --asc $(DESIGN).asc -l nextpnrLog_$(NEXTPNR_LOG).log
	icetime -p pcf/$(DESIGN).pcf -P uwg30 -d up5k -t $(DESIGN).asc
	icepack $(DESIGN).asc $(DESIGN).bin

clean:
	rm -f *.json *.blif *.asc *.bin
