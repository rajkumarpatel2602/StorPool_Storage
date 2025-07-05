/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

/*
 * Problem: FizzBuzz
 * Write a program that outputs the numbers from 1 to 100. If the number is divisible by 3, instead
 * of it print “A”, if it’s divisible by 5 - “B”, if it’s divisible by 15 - “AB”. The catch is to write it without
 * any conditionals/ifs, including for/while loops.
 */

#include <stdio.h>
#include <stdbool.h>
 
char *a[4] = {NULL, "A", "B", "AB"};
 
void printSequence(int i) {
    
    int divisibleby3 = (i%3 == 0);
    int divisibleby5 = (i%5 == 0);
    int query = (i <= 100) ? (divisibleby5 << 1) | divisibleby3 :  101;
    
    switch(query) {
        case 0: printf(" %d", i); break;
        case 1:
        case 2:
        case 3: printf(" %s",a[query]); break;
        case 101: return;
        default: break;
    }
    
    printSequence(i+1);
}
 
int main() {
    
    int i=1;
    
    printSequence(i);

    return 0;
}

