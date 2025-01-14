#include <iostream>
using namespace std;

class _6502
{
    public:
        _6502();
        ~_6502();

        void connectBus(Bus *n);

        void clock(); //Cycles the clock
        void reset(); //Resets the system
        void interruptReq(); //Requests the CPU to stop what its doing
        void nonMaskInterrupt(); //This request can't be stopped

        enum flags
        {
            C = (1<<0), //Set if previous operation resulted in a carryout bit
            Z = (1<<1), //Set if previous operation result was 0
            I = (1<<2), //If set, CPU ignores interrupt commands
            D = (1<<3), //If set, arithmetic follows BCD rules
            B = (1<<4), //Break flag, raised when an interrupt request goes through
            U = (1<<5), //Unused Bit
            V = (1<<6), //Set if previous operation results in an illegal 2s complement, (Overflow)
            N = (1<<7), //Set if the result of the previous operation was negative (MSD == 1)
        
        };

        #pragma region Addressing Modes //ADDRESSING MODES

        // IMP - Implied addressing mode
        // No operand is required; the instruction operates implicitly on a specific register or value.
        uint8_t IMP();

        // IMM - Immediate addressing mode
        // The operand is a literal value provided directly in the instruction.
        uint8_t IMM();

        // ZP0 - Zero Page addressing mode
        // Accesses memory within the first 256 bytes of memory (0x0000 to 0x00FF).
        uint8_t ZP0();

        // ZPX - Zero Page,X addressing mode
        // Adds the value of the X register to a zero-page address for indirect access.
        uint8_t ZPX();

        // ZPY - Zero Page,Y addressing mode
        // Adds the value of the Y register to a zero-page address for indirect access.
        uint8_t ZPY();

        // REL - Relative addressing mode
        // Used for branch instructions; calculates the branch target relative to the current program counter.
        uint8_t REL();

        // ABS - Absolute addressing mode
        // Specifies a complete 16-bit address to access directly.
        uint8_t ABS();

        // ABX - Absolute,X addressing mode
        // Adds the value of the X register to a 16-bit absolute address for indexed access.
        uint8_t ABX();

        // ABY - Absolute,Y addressing mode
        // Adds the value of the Y register to a 16-bit absolute address for indexed access.
        uint8_t ABY();

        // IND - Indirect addressing mode
        // Reads a 16-bit address from a specified location to determine the actual target address.
        uint8_t IND();

        // IZX - Indexed Indirect addressing mode (Indirect,X)
        // Uses the X register to offset into a zero-page table of addresses and fetch the target address indirectly.
        uint8_t IZX();

        // IXY - Indirect Indexed addressing mode (Indirect,Y)
        // Fetches a base address from a zero-page location and adds the Y register to calculate the target address.
        uint8_t IXY();

        #pragma endregion

        #pragma region //OPCODES

        // ADC - Add with Carry
        // Adds a value to the accumulator with the carry bit.
        uint8_t ADC();

        // AND - Logical AND
        // Performs a bitwise AND between the accumulator and a value.
        uint8_t AND();

        // ASL - Arithmetic Shift Left
        // Shifts the bits of a value left by one position; the carry bit is set to the bit that was shifted out.
        uint8_t ASL();

        // BCC - Branch if Carry Clear
        // Branches to a new location if the carry flag is clear.
        uint8_t BCC();

        // BCS - Branch if Carry Set
        // Branches to a new location if the carry flag is set.
        uint8_t BCS();

        // BEQ - Branch if Equal
        // Branches to a new location if the zero flag is set.
        uint8_t BEQ();

        // BIT - Bit Test
        // Tests bits in a value using the accumulator without affecting the accumulator.
        uint8_t BIT();

        // BMI - Branch if Minus
        // Branches to a new location if the negative flag is set.
        uint8_t BMI();

        // BNE - Branch if Not Equal
        // Branches to a new location if the zero flag is clear.
        uint8_t BNE();

        // BPL - Branch if Positive
        // Branches to a new location if the negative flag is clear.
        uint8_t BPL();

        // BRK - Force Interrupt
        // Forces a software interrupt, pushing the program counter and processor status onto the stack.
        uint8_t BRK();

        // BVC - Branch if Overflow Clear
        // Branches to a new location if the overflow flag is clear.
        uint8_t BVC();

        // BVS - Branch if Overflow Set
        // Branches to a new location if the overflow flag is set.
        uint8_t BVS();

        // CLC - Clear Carry Flag
        // Clears the carry flag to 0.
        uint8_t CLC();

        // CLD - Clear Decimal Mode
        // Clears the decimal mode flag to 0.
        uint8_t CLD();

        // CLI - Clear Interrupt Disable
        // Clears the interrupt disable flag to 0.
        uint8_t CLI();

        // CLV - Clear Overflow Flag
        // Clears the overflow flag to 0.
        uint8_t CLV();

        // CMP - Compare Accumulator
        // Compares a value with the accumulator and sets flags accordingly.
        uint8_t CMP();

        // CPX - Compare X Register
        // Compares a value with the X register and sets flags accordingly.
        uint8_t CPX();

        // CPY - Compare Y Register
        // Compares a value with the Y register and sets flags accordingly.
        uint8_t CPY();

        // DEC - Decrement Memory
        // Decreases the value at a memory location by 1.
        uint8_t DEC();

        // DEX - Decrement X Register
        // Decreases the X register by 1.
        uint8_t DEX();

        // DEY - Decrement Y Register
        // Decreases the Y register by 1.
        uint8_t DEY();

        // EOR - Exclusive OR
        // Performs a bitwise XOR between the accumulator and a value.
        uint8_t EOR();

        // INC - Increment Memory
        // Increases the value at a memory location by 1.
        uint8_t INC();

        // INX - Increment X Register
        // Increases the X register by 1.
        uint8_t INX();

        // INY - Increment Y Register
        // Increases the Y register by 1.
        uint8_t INY();

        // JMP - Jump
        // Sets the program counter to a new location.
        uint8_t JMP();

        // JSR - Jump to Subroutine
        // Pushes the current program counter onto the stack and jumps to a new location.
        uint8_t JSR();

        // LDA - Load Accumulator
        // Loads a value into the accumulator.
        uint8_t LDA();

        // LDX - Load X Register
        // Loads a value into the X register.
        uint8_t LDX();

        // LDY - Load Y Register
        // Loads a value into the Y register.
        uint8_t LDY();

        // LSR - Logical Shift Right
        // Shifts the bits of a value right by one position; the carry bit is set to the bit that was shifted out.
        uint8_t LSR();

        // NOP - No Operation
        // Performs no operation but consumes cycles.
        uint8_t NOP();

        // ORA - Logical OR
        // Performs a bitwise OR between the accumulator and a value.
        uint8_t ORA();

        // PHA - Push Accumulator
        // Pushes the accumulator onto the stack.
        uint8_t PHA();

        // PHP - Push Processor Status
        // Pushes the processor status onto the stack.
        uint8_t PHP();

        // PLA - Pull Accumulator
        // Pulls the top value off the stack into the accumulator.
        uint8_t PLA();

        // PLP - Pull Processor Status
        // Pulls the top value off the stack into the processor status register.
        uint8_t PLP();

        // ROL - Rotate Left
        // Rotates the bits of a value left through the carry flag.
        uint8_t ROL();

        // ROR - Rotate Right
        // Rotates the bits of a value right through the carry flag.
        uint8_t ROR();

        // RTI - Return from Interrupt
        // Restores the program counter and status register from the stack.
        uint8_t RTI();

        // RTS - Return from Subroutine
        // Restores the program counter from the stack.
        uint8_t RTS();

        // SBC - Subtract with Carry
        // Subtracts a value and the carry bit from the accumulator.
        uint8_t SBC();

        // SEC - Set Carry Flag
        // Sets the carry flag to 1.
        uint8_t SEC();

        // SED - Set Decimal Flag
        // Sets the decimal mode flag to 1.
        uint8_t SED();

        // SEI - Set Interrupt Disable
        // Sets the interrupt disable flag to 1.
        uint8_t SEI();

        // STA - Store Accumulator
        // Stores the accumulator at a memory location.
        uint8_t STA();

        // STX - Store X Register
        // Stores the X register at a memory location.
        uint8_t STX();

        // STY - Store Y Register
        // Stores the Y register at a memory location.
        uint8_t STY();

        // TAX - Transfer Accumulator to X
        // Copies the accumulator to the X register.
        uint8_t TAX();

        // TAY - Transfer Accumulator to Y
        // Copies the accumulator to the Y register.
        uint8_t TAY();

        // TSX - Transfer Stack Pointer to X
        // Copies the stack pointer to the X register.
        uint8_t TSX();

        // TXA - Transfer X to Accumulator
        // Copies the X register to the accumulator.
        uint8_t TXA();

        // TXS - Transfer X to Stack Pointer
        // Copies the X register to the stack pointer.
        uint8_t TXS();

        // TYA - Transfer Y to Accumulator
        // Copies the Y register to the accumulator.
        uint8_t TYA();

        // XXX - Illegal Opcode
        // Handles unimplemented or illegal opcodes by performing a no-operation.
        uint8_t XXX();

        #pragma endregion

        #pragma region //REGISTERS

        uint8_t status = 0x00; 
        uint8_t A = 0x00; //Accumulator
        uint8_t X = 0x00; //X register
        uint8_t Y = 0x00; //Y register
        uint8_t SP = 0x00; //Stack Pointer
        uint16_t PC = 0x00; //Program Counter

        uint8_t fetch(); // gets data from memory
        uint8_t fetched(); //holds the retreived data

        uint16_t addressAbs = 0x0000; //Depending on the addressing mode, we want to pull from different parts of memory
        uint16_t relativeAddress = 0x00; //When jumping in memory, we can only jump a certain distance from where the function was called. This holds that offset
        uint8_t opcode = 0x00; //Holds the opcode that acccesses the operation we want to execute
        uint8_t cycles = 0x00; //Holds the amount of the cycles left for each opcode

        #pragma endregion
    
    private:

        Bus *bus = nullptr;
        uint8_t r(uint16_t address);
        void w(uint16_t address, uint8_t data);

        uint8_t getFlag(flags f);
        void setFlag(flags f, bool v);

        struct OPERATION
        {
            string name; //holds the mneumonic for the opcode
            uint8_t(_6502::*operate)(void) = nullptr; //function pointer to the opcode
            uint8_t(_6502::*addressMode)(void) = nullptr; //function pointer to the address mode
            uint8_t cycles = 0;
        };

        vector<OPERATION> lookup;
};