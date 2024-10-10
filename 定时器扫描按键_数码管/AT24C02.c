#include <REGX52.H>
#include "i2c.h"

#define AT24C02_Add 0xA0 // AT24C02���豸��ַ��7λ��ַ���϶�дλ

/**
 * @brief  AT24c02д��һ���ֽ�
 * @param  wordAddҪд��ĵĵ�ַ DataҪд�������
 * @retval ��
 */
void AT24C02_writebyte(unsigned char wordAdd, unsigned char Data)
{
    i2c_start();
    i2c_sendByte(AT24C02_Add);  // ����д�������豸��ַ��0xA0��
    i2c_receiveAck();
    i2c_sendByte(wordAdd);      // ���ʹ洢��ַ
    i2c_receiveAck();
    i2c_sendByte(Data);         // ��������
    i2c_receiveAck();
    i2c_stop();                 // ֹͣI2C����
}

/**
 * @brief  AT24c02��ȡһ���ֽ�
 * @param  wordAddҪ�����ĵ�ַ 
 * @retval Ҫ����������
 */
unsigned char AT24C02_receiveByte(unsigned char wordAdd)
{
    unsigned char Data;
    i2c_start();
    i2c_sendByte(AT24C02_Add);      // ����д�������豸��ַ��0xA0��
    i2c_receiveAck();
    i2c_sendByte(wordAdd);          // ����Ҫ��ȡ�Ĵ洢��ַ
    i2c_receiveAck();

    // ���¿�ʼI2C�����������
    i2c_start();
    i2c_sendByte(AT24C02_Add | 0x01); // ���Ͷ��������豸��ַ��0xA1��
    i2c_receiveAck();
    
    Data = i2c_receiveByte();        // ��������
    i2c_sendAck(1);                  // ����NACK����ʾֹͣ��ȡ
    i2c_stop();                      // ֹͣI2C����
    return Data;
}
