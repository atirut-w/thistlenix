# Thistlenix
An attempt at a Unix-like kernel for the Thistle OpenComputers add-on.

Currently, most of the work are just perfecting the build system and figuring out what I can do with Thistle. The actual kernel will be worked on once I get the hang of Thistle's architecture.

## Archived
This project has been archived, because during the development, I have discovered a fetal bug with Thisle.

The bug affects indirect indexed memory accesses(`(zpptr),y`) when the resulting address crosses page boundaries. When this happens, the data will not be read or written from the next page, but the current page with the LSB of the address wrapped around. This project will be archived until the bug is fixed by Thistle devs.

# Building
Building Thistlenix requires you to have the [CC65 cross-development package](https://cc65.github.io/) and GNU Make. Once you have those installed, just run `make` in the project directory. The compiled kernel will be placed in the `build` directory along with a map file.

When rebuilding, you may want to run `make clean` to remove the old assembly and object files.

# Running the kernel
NOTE: This assumes you already have Minecraft 1.9.4 with Forge, OpenComputers and Thistle installed.

Just copy the built kernel to the root of your boot drive and rename it to "Thistle".

Yes, that is all.
