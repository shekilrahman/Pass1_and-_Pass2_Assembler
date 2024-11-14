SIC/XE Assembler Simulator
This project is a simple implementation of a SIC/XE Assembler simulator, which processes an assembly language input file and generates object code. The program also handles the symbol table and opcode table. It is written in C and designed to parse assembly instructions, calculate addresses, and create the necessary output files.

Features
Parse Assembly Instructions: The simulator reads assembly instructions from a given input file.
Symbol Table Generation: It creates a symbol table to store the labels and their corresponding addresses.
Opcode Table Handling: It processes the opcodes and generates object code.
Address Calculation: The simulator calculates addresses and updates them based on instruction types, such as RESW.
Hexadecimal Addressing: The program uses hexadecimal arithmetic for address calculation.
File Details
Input File (<input_file>): The assembly code file to be processed. It should contain assembly instructions with labels, opcodes, and operands.
Symbol Table File (symtab): A file that stores labels and their respective addresses.
Opcode Table File (optab): The file to store opcodes and their corresponding machine codes (if applicable).
Output File (<output_file>): The output file that contains the address, label, opcode, and operand of each instruction, along with the total length of the program.
How to Use
Requirements:
A C compiler (e.g., GCC).
Compilation:
To compile the program, use the following command:

bash
Copy code
gcc -o pass pass.c
Execution:
Run the program with the following command:

bash
Copy code
./pass <input_file> [<output_file>]
<input_file>: The assembly input file to be processed.
<output_file> (optional): The output file where the processed data will be written. If not provided, the default file output will be used.
Example:
Create an assembly code file named program.asm with the following sample instructions:
sql
Copy code
LABEL   START  1000
        ADD    A
        RESW   1
        END
Run the program:
bash
Copy code
./pass program.asm
The program will generate the following:
A symbol table (symtab) with labels and their addresses.
An opcode table (optab).
An output file (output) containing the instruction details.
Functions
parse_line: This function parses a line from the input file and separates the label, opcode, and operand.
hexAdd: This function adds a hexadecimal value to the current address and updates the length accordingly.
Contributing
Feel free to fork this repository and contribute by opening an issue or a pull request.

License
This project is licensed under the MIT License.

