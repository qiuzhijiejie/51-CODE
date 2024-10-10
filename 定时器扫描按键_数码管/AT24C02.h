#ifndef __AT24C02__H__
#define __AT24C02__H__

void AT24C02_writebyte(unsigned char wordAdd, unsigned char Data);
unsigned char AT24C02_receiveByte(unsigned char wordAdd);
#endif