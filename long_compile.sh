#!/bin/bash

# A shell script to automatically compile main.c in
# multiple steps, to show the phases of compilation
# that a C program goes through.

# Note that all of this can be skipped by just running:
#    gcc -o main main.c stuff.c && ./main

if [ -d "preprocessing" ] ; then
    rm -rf "preprocessing"
fi
if [ -d "compilation" ] ; then
    rm -rf "compilation"
fi
if [ -d "assembly" ] ; then
    rm -rf "assembly"
fi
if [ -d "linking" ] ; then
    rm -rf "linking"
fi

# Preprocessor: expand macros, remove comments, include header files.
mkdir preprocessing
# -E flag stops gcc at the preprocessing stage.
gcc -E main.c > preprocessor/main.i
gcc -E stuff.c > preprocessor/stuff.i

# Compiler: translate C code into machine-specific assembly code.
mkdir compilation
# -S flag stops gcc at the compilation stage, spits out assembly files.
gcc -S preprocessor/main.i > compilation/main.s
gcc -S preprocessor/stuff.i > compilation/stuff.s

# Assembler: translate ASM code into machine (object) code.
# At this point, the code is no longer human-readable at all.
mkdir assembly
# -c flag stops gcc at the assembly stage, spits out object files.
gcc -c compilation/main.s > assembly/main.o
gcc -c compilation/stuff.s > assembly/stuff.o

# Linker: combine object files into one executable.
mkdir linking
# -o flag specifies the name of the final output file.
gcc -o linking/main assembly/main.o assembly/stuff.o

# Finally, execute the generated machine code.
./linking/main