#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Byte;
typedef unsigned int Word;

struct Memory
{
    static const int MAX_MEM = 1024 * 64; //This is because there are 1024 8 byte addresses in the emulated memory
    Byte Data[MAX_MEM];

    Byte operator[](int index)
    {
        return Data[index];
    }

    void intitialize()
    {
        for( int i = 0; i < MAX_MEM; i++ )
        {
            Data[i] = 0;
        }
    }

};

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

    void reset(Memory& mem)
    {
        PC = 0xFFFC; //Where the CPU will initially look for an instruction
        SP = 0x0100; 

        C = Z = I = D = B = V = N = 0; //Clears PS bitmap
        
        //Clears Registers
        A = 0;
        X = 0;
        Y = 0;

        mem.intitialize();
    }

    Byte FetchByte( Memory& mem )
    {
        Byte data = mem[PC]; //pulls the current instruction waiting to be executed
        PC++; //moves the program counter to the next instruction
        return data;

    }
    void execute(Memory& mem, int cycles)
    {
        for(int i  = cycles; i > 0; i--)
        {
            Byte instruction = FetchByte( mem );
        }
    }

};


int main()
{
    CPU cpu; 
    Memory mem;

    cpu.reset(mem);
    cpu.execute(mem, 2);
    return 0;
}