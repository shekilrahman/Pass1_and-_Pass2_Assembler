#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct token {
    char label[10];
    char opcode[10];
    char operand[10];
};

// Function declarations
void hexAdd(char*, char*, int);
struct token parse_line(char[]);

int main(int argc, char *argv[]) {
    FILE *ipt, *out, *st, *ot;
    
    // Check for correct argument count
    if (argc < 2) {
        printf("Usage: ./pass <input_file> <output_file>\n");
        return 0;
    }
    
    // Open files
    ipt = fopen(argv[1], "r");
    st = fopen("symtab", "w+");
    ot = fopen("optab", "w+");
    
    if (argc > 2) {
        out = fopen(argv[2], "w+");
    } else {
        out = fopen("output", "w+");
    }

    // Check if files opened successfully
    if (ipt == NULL || st == NULL || out == NULL || ot == NULL) {
        printf("Error: resource files are missing\n");
        return 0;
    }
    
    // Initialize variables
    char cur_inst[200];
    char cur_adr[5] = "null";
    char srt_adr[5];
    char t_len[5] = "0000";
    struct token c_token;
    
    printf("Execution STARTS ----\n\n");
    
    // Process each instruction from the input file
    while (fgets(cur_inst, sizeof(cur_inst), ipt) != NULL) {
        c_token = parse_line(cur_inst);
        
        // Skip empty lines or lines without opcode
        if (c_token.opcode[0] == '\0') {
            continue;
        }
        
        // Handle START opcode
        if (strcmp(c_token.opcode, "START") == 0) {
            strcpy(cur_adr, c_token.operand);
            strcpy(srt_adr, cur_adr);
        } 
        // Skip lines with "null" opcode
        else if (strcmp(c_token.opcode, "null") == 0) {
            continue;
        } 
        // Process instructions if the address is set
        else if (strcmp(cur_adr, "null") != 0) {
            printf("Executing -> %s\n", cur_adr);
            
            // Write label and address to the symbol table
            if (strcmp(c_token.label, "") != 0) {
                fprintf(st, "%s\t%s\n", c_token.label, cur_adr);
            }
            
            // Write instruction details to the output file
            fprintf(out, "%s\t%s\t%s\t%s\n", cur_adr, c_token.label, c_token.opcode, c_token.operand);
            
            // Handle RESW (reserve word) instructions
            if (strcmp(c_token.opcode, "RESW") == 0) {
                hexAdd(cur_adr, t_len, atoi(c_token.operand) * 3);
            } else {
                hexAdd(cur_adr, t_len, 3); // Assuming other instructions use 3 bytes
            }
        } else {
            // If no starting address is found, exit the loop
            printf("No starting address found!\n");
            break;
        }
    }
    
    // Write the total length at the end of the output file
    fprintf(out, "%s\n", t_len);
    
    // Close all files
    fclose(ipt);
    fclose(st);
    fclose(ot);
    fclose(out);
    
    printf("\nExecution ENDS ----\n");
}

// Function to parse a line of instruction
struct token parse_line(char line[]) {
    struct token t = {"", "", ""};  // Initialize with empty strings
    char *token;
    int len = 0;
    
    char temp_copy[100], temp[100];
    strcpy(temp, line);
    strcpy(temp_copy, temp);
    
    token = strtok(temp, " \t\n"); // Tokenize by spaces, tabs, and newlines
    
    // Count the number of tokens in the line
    while (token != NULL) {
        len++;
        token = strtok(NULL, " \t\n");
    }
    
    // Tokenize again to fill the struct based on the number of tokens
    token = strtok(temp_copy, " \t\n");
    
    if (len == 2) {
        strcpy(t.opcode, token);
        token = strtok(NULL, " \t\n");
        strcpy(t.operand, token);
    } else if (len == 3) {
        strcpy(t.label, token);
        token = strtok(NULL, " \t\n");
        strcpy(t.opcode, token);
        token = strtok(NULL, " \t\n");
        strcpy(t.operand, token);
    } else if (len == 1) {
        strcpy(t.opcode, token);
    } else {
        strcpy(t.opcode, "null");
    }
    
    return t;
}

// Function to add hexadecimal values
void hexAdd(char *hexVal, char *hexLen, int add) {
    unsigned int result = (unsigned int)strtol(hexVal, NULL, 16);
    unsigned int length = (unsigned int)strtol(hexLen, NULL, 16);
    
    result += add;  // Add the value to the current address
    length += add;  // Add the value to the length
    
    // Convert back to hexadecimal and update the values
    sprintf(hexVal, "%X", result);
    sprintf(hexLen, "%X", length);
}

