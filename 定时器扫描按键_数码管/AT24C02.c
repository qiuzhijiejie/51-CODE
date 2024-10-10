#include <REGX52.H>
#include "i2c.h"

#define AT24C02_Add 0xA0 // AT24C02的设备地址，7位地址加上读写位

/**
 * @brief  AT24c02写入一个字节
 * @param  wordAdd要写入的的地址 Data要写入的数据
 * @retval 无
 */
void AT24C02_writebyte(unsigned char wordAdd, unsigned char Data)
{
    i2c_start();
    i2c_sendByte(AT24C02_Add);  // 发送写操作的设备地址（0xA0）
    i2c_receiveAck();
    i2c_sendByte(wordAdd);      // 发送存储地址
    i2c_receiveAck();
    i2c_sendByte(Data);         // 发送数据
    i2c_receiveAck();
    i2c_stop();                 // 停止I2C传输
}

/**
 * @brief  AT24c02读取一个字节
 * @param  wordAdd要读出的地址 
 * @retval 要读出的数据
 */
unsigned char AT24C02_receiveByte(unsigned char wordAdd)
{
    unsigned char Data;
    i2c_start();
    i2c_sendByte(AT24C02_Add);      // 发送写操作的设备地址（0xA0）
    i2c_receiveAck();
    i2c_sendByte(wordAdd);          // 发送要读取的存储地址
    i2c_receiveAck();

    // 重新开始I2C，进入读操作
    i2c_start();
    i2c_sendByte(AT24C02_Add | 0x01); // 发送读操作的设备地址（0xA1）
    i2c_receiveAck();
    
    Data = i2c_receiveByte();        // 接收数据
    i2c_sendAck(1);                  // 发送NACK，表示停止读取
    i2c_stop();                      // 停止I2C传输
    return Data;
}
