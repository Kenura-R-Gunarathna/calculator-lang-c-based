// main.c
#include <stdio.h>
#include <string.h>
#include "calculator.h"

int main() {

    printf("----------------------\n");
    printf("KRAG C Lang Calculator\n");
    printf("----------------------\n");
    printf("Enter `quit` to exit the application. Enter `help` to list out commands.\n");
    
    while(1){
        int A, B, Result;
        char OpCode[10];  // Increased size for OpCode to accommodate longer strings

        printf(">> ");
        // Using "%s" for the OpCode, then we will read A and B separately
        if (scanf("%s", OpCode) != 1) {
            printf("Invalid input.\n");
            continue;
        }

        if(strcmp("quit", OpCode) == 0){
            printf("Quiting application...\n");
            break;
        }

        if(strcmp("help", OpCode) == 0){
            printf("add x y  :- Add two integers.\n");
            printf("sub x y  :- Subtract two integers.\n");
            printf("mul x y  :- Multiply two integers.\n");
            printf("div x y  :- Divide two integers.\n");
            printf("mod x y  :- Remainder of division of two integers.\n");
            continue;
        }
        
        // Reading operands after the opcode
        if (scanf("%d, %d", &A, &B) != 2) {
            printf("Invalid input. Please enter two integers after the operation.\n");
            continue;
        }

        // Handle different operations
        if(strcmp("add", OpCode) == 0){
            Result = add(A, B);
        } else if(strcmp("sub", OpCode) == 0){
            Result = sub(A, B);
        } else if(strcmp("mul", OpCode) == 0){
            Result = mul(A, B);
        } else if(strcmp("div", OpCode) == 0){
            // Prevent division by zero
            if (B == 0) {
                printf("Error: Division by zero.\n");
                continue;
            }
            Result = div(A, B);
        } else if(strcmp("mod", OpCode) == 0){
            // Prevent division by zero
            if (B == 0) {
                printf("Error: Modulo by zero.\n");
                continue;
            }
            Result = mod(A, B);
        } else {
            printf("Invalid Opcode! Use 'help' to see the commands.\n");
            continue;
        }

        printf("Result: %d\n", Result);
    }

    return 0;
}
