#include <iostream>
#include <cstdint> //renames types to explicit names
#include "_6502.h"

using namespace std;

class Bus
{
    public:
        Bus();
        ~Bus();

        void write(uint16_t address, uint8_t data); 
        uint8_t read(uint16_t address, bool onlyRead = false);

        _6502 cpu; //Bus class contains a CPU

        uint8_t* RAM = new uint8_t[64 * 1024]; //Creates memory on the heap to imitate the ram connected to the 6502

};