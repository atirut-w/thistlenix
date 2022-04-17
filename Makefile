# Compiler, assembler and linker
CC65 = cc65
CA65 = ca65
LD65 = ld65

compile:
	mkdir -p build
	$(CA65) --cpu 65c02 src/main.s -o build/kernel.o
	$(LD65) -C 3rd/Thistle/cc65/thistle.cfg -m build/kernel.map build/kernel.o -o build/kernel.bin

clean:
	@rm -rf build/kernel.o build/kernel.map
