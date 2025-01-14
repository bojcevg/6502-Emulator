#include "_6502.h"
#include "Bus.h"

_6502::_6502()
{

}

_6502::~_6502()
{

}

uint8_t _6502::r(uint16_t address)
{
    return bus->read(address, false);
}

void _6502::w(uint16_t address, uint8_t data)
{
    return bus->write(address, data);
}