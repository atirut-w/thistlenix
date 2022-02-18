# Compiler, assembler and linker
CC65 = cc65
CA65 = ca65
LD65 = ld65

build: src link

compile:
	@mkdir -p build/s
	@$(CC65) -t none --cpu 65c02 -O -o build/s/main.s src/main.c

assemble: compile
	@mkdir -p build/o
	@for i in src/*.s; do $(CA65) --cpu 65c02 $$i -o build/o/`basename $$i .s`.o; done
	@for i in build/s/*.s; do $(CA65) --cpu 65c02 $$i -o build/o/`basename $$i .s`.o; done

link: assemble
	@$(LD65) -C 3rd/Thistle/cc65/thistle.cfg -o build/kernel build/o/*.o 3rd/Thistle/cc65/thistle.lib

clean:
	@rm -rf build/s build/o
