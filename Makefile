# Compiler, assembler and linker
# CC65 = cc65
CA65 = ca65
LD65 = ld65

build: assemble link

# compile:
# 	mkdir -p build/s
# 	find src/ -name '*.s' -exec cp {} build/s/ \;
# 	find src/ -name '*.c' -exec sh -c '$(CC65) -T -t none --cpu 65c02 -Isrc/include {} -o build/s/$$(basename {} .c).s' \;

assemble:
	mkdir -p build/o
	find src/ -name '*.s' -exec sh -c '$(CA65) --cpu 65c02 {} -o build/o/$$(basename {} .s).o' \;

link:
	$(LD65) build/o/*.o -o build/kernel.bin -m build/kernel.map -C 3rd/Thistle/cc65/thistle.cfg
