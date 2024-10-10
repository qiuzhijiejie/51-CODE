#ifndef __i2c_H__
#define __i2c_H__

void i2c_start(void);
void i2c_stop(void);
void i2c_sendByte(unsigned char byte);
unsigned char i2c_receiveByte(void);
void i2c_sendAck(unsigned char ack);
unsigned char i2c_receiveAck(void);


#endif