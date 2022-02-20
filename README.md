# Thistlenix
An attempt at a Unix-like kernel for the Thistle OpenComputers add-on.

Currently, most of the work are just perfecting the build system and figuring out what I can do with Thistle. The actual kernel will be worked on once I get the hang of Thistle's architecture.

# Building
Building Thistlenix requires you to have the [CC65 cross-development package](https://cc65.github.io/) and GNU Make. Once you have those installed, just run `make` in the project directory. The compiled kernel will be placed in the `build` directory along with a map file.

When rebuilding, you may want to run `make clean` to remove the ols assembly and object files.
