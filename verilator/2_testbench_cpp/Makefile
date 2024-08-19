
MODULE		= dut

all:	gtkwave

verilate: $(MODULE).v $(MODULE).tb.cpp
	verilator -Wall --trace -cc $(MODULE).v --exe $(MODULE).tb.cpp

build: verilate
	make -C obj_dir -f V$(MODULE).mk

run: build
	./obj_dir/V$(MODULE) +vcd

gtkwave: run $(MODULE).vcd
	gtkwave	$(MODULE).vcd &

clean:
	rm -rf ./obj_dir *.vcd

.PHONY:	verilate build run gtkwave clean 
