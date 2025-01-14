#include "Bus.h"

Bus::Bus() //Constructor 
{
    for(int i = 0; i < 64*1024; i++) //Sets all of the memory to zero 
    {
        RAM[i] = 0x00;
    }

    cpu.connectBus(this); //on creation, connects the bus to the cpu 
}

Bus::~Bus()
{
    delete RAM;
}

void Bus::write(uint16_t address, uint8_t data)
{
    if (address >= 0x0000 && address <= 0xFFFF) //ensures that data is being written to a valid location 
       {
            RAM[address] = data;
       }
    
    
}

uint8_t Bus::read(uint16_t address, bool readOnly)
{
    if (address >= 0x0000 && address <= 0xFFFF) //ensures that data is being read from a valid location 
        {
            return RAM[address];
        }
    else
        {
            return 0x0000; //base case
        }
        
}