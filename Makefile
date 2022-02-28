# Compiler, assembler and linker
CC65 = cc65
CA65 = ca65
LD65 = ld65

build: src compile assemble link

compile:
	mkdir -p build/s
	find src/ -name '*.s' -exec cp {} build/s/ \;

assemble:
	mkdir -p build/o
	for f in build/s/*.s; do $(CA65) --cpu 65c02 $$f -o build/o/`basename $$f .s`.o; done

link:
	$(LD65) -C 3rd/Thistle/cc65/thistle.cfg -m build/kernel.map -o build/kernel build/o/*.o

clean:
	@rm -rf build/s build/o
