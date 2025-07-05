/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

/* 
 * problem: 'Counting' 
 * As input to your program, there is a binary file containing 1 billion 32-bit integer numbers,
 * stored as uint32_t. The size of the file is 4,000,000,000 bytes.
 * а) count the unique numbers. For example:
 * given input -> output
 * 0x100 0x100 0xfff 0xfff -> 2 unique numbers
 * 0x100 0x100 0x100 0x100 -> 1 unique number
 * 0x100 0x100 0x800 0xfff -> 3 unique numbers
 * b) count how many numbers are seen ONLY once. For example:
 * given input -> output
 * 0x100 0x100 0xfff 0xfff -> 0 numbers seen only once
 * 0x100 0x100 0x100 0x100 -> 0 numbers seen only once
 * 0x100 0x100 0x800 0xfff -> 2 numbers seen only once
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <error.h>
#include <stdint.h>
 
int *countUniqueNums(const char *input) {
    
    static uint32_t result[2] = {-1, -1}; /* pair of {uniqueue number, unique occurrance} */
    
    FILE *fp = fopen(input, "rb");
    
    if (!fp) {
        perror("Error opening input file");
        return result;
    };
    
    /* bit-array to mark 1 billion inteegr entries */
    uint32_t DATA_SIZE_IN_BYTES = 4 * 1000 * 1000 * 1000;
    uint32_t ENTRY_SIZE = 4;
    uint32_t TOTAL_ENTRIES = (DATA_SIZE_IN_BYTES/TOTAL_ENTRIES);
    
    /* allocate local bitarray */
    uint8_t arr[TOTAL_ENTRIES/8] = {};
    
    /* read 4 bytes at a time and mark the presence in the bitarray */
    uint32_t num;
    uint32_t unique_number = 0, unique_occurrence = 0;
    
    
    while ((fread(&num, 4, 1, fp)) > 0) {
        
        /* check if not set */
        if (!(arr[num/8] & 1 << num%8)) {
            /* set */
            arr[num/8] |= 1 << (num%8);
            unique_number++;
            unique_occurrence++;
        } 
        else {
            unique_occurrence--;
        }
    }

    result[0] = unique_number;
    result[1] = unique_occurrence;
    
    fclose(fp);
    
    return result;
}
 
int main() {
    
    const char *filename = "./inputfile.bin"; /* input file name */
    
    uint32_t *result = countUniqueNums(filename);    
    
    printf("Unique numbers: %u\n", result[0]); 
    printf("Unique numbers: %u\n", result[1]); 

    return 0;
}

