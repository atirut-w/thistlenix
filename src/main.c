void main() {
    // Ported from https://github.com/gamax92/Thistle/wiki/Thistle-Boot-ROM-Manual#a-simple-test
    // This should result in the same assembly code as the original.
    *(char *)0xe003 = 0x41;
    *(char *)0xe003 = 0x0a;
}
