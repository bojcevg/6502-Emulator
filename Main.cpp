#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

struct CPU
{
    Word PC; //Program counter, points to the next instruction to be executed
    Word SP; //Stack pointer, points to the next available memory in the stack (8bit location)

    Byte A; //Accumulator, used for artithmetic and logical operations
    Byte X , Y; //Registers

    Byte C : 1; //Carry, set it result of an arithmetic instruction results in overflow
    Byte Z : 1; //Zero, set if result of last operation was 0
    Byte I : 1; //Interupt Disable, if set the CPU will ignore all incoming interrupt commands
    Byte D : 1; //Decimal mode, if active, arithmetic follows BCD rules
    Byte B : 1; //Break, set when a break instruction has been executed and an interrupt has been created to processes it
    Byte V : 1; //Overflow, set if an arithmetic operaiton resulted in an invalid 2's complement
    Byte N : 1; //Negative, set if the last operation was negative (Bit 7 is set to 1)

};

int main()
{

    return 0;
}