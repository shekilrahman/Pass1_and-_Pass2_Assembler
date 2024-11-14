# SIC/XE Assembler Simulator

This project is a simple implementation of a **SIC/XE Assembler** simulator, which processes an assembly language input file and generates object code. The program also handles the symbol table and opcode table. It is written in **C** and designed to parse assembly instructions, calculate addresses, and create the necessary output files.

## Features

- **Parse Assembly Instructions:** The simulator reads assembly instructions from a given input file.
- **Symbol Table Generation:** It creates a symbol table to store the labels and their corresponding addresses.
- **Opcode Table Handling:** It processes the opcodes and generates object code.
- **Address Calculation:** The simulator calculates addresses and updates them based on instruction types, such as `RESW`.
- **Hexadecimal Addressing:** The program uses hexadecimal arithmetic for address calculation.

## File Details

- **Input File** (`<input_file>`): The assembly code file to be processed. It should contain assembly instructions with labels, opcodes, and operands.
- **Symbol Table File** (`symtab`): A file that stores labels and their respective addresses.
- **Opcode Table File** (`optab`): The file to store opcodes and their corresponding machine codes (if applicable).
- **Output File** (`<output_file>`): The output file that contains the address, label, opcode, and operand of each instruction, along with the total length of the program.

## How to Use

### Requirements:
- A C compiler (e.g., GCC).

### Compilation:
To compile the program, use the following command:

```bash
gcc -o pass pass.c
