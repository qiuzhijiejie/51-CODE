#include <REGX52.H>
sbit SDA = P2^0;
sbit SCL = P2^1;

/**
 * @brief I2C��ʼ�ź�
 * @param ��
 * @retval ��
 */
void i2c_start(void)
{
    SDA = 1;
    SCL = 1;
    SDA = 0;
    SCL = 0;
}

/**
 * @brief I2C�����ź�
 * @param ��
 * @retval ��
 */
void i2c_stop(void)
{
    SDA = 0;
    SCL = 1;
    SDA = 1;
}

/**
 * @brief I2C����һ���ֽ�
 * @param byte Ҫ���͵��ֽ�
 * @retval ��
 */
void i2c_sendByte(unsigned char byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        SDA = (byte & (0x80 >> i));  // �Ӹ�λ��ʼ����
        SCL = 1;                     // ��������ʱ��
        SCL = 0;                     // ʱ������
    }
}

/**
 * @brief I2C����һ���ֽ�
 * @param ��
 * @retval ���յ����ֽ�
 */
unsigned char i2c_receiveByte(void)
{
    unsigned char i, byte = 0;
    SDA = 1; // �ͷ� SDA ��
    for (i = 0; i < 8; i++)
    {
        SCL = 1;                     // ����ʱ��
        if (SDA)                     // ��ȡ SDA ��ֵ
        {
            byte |= (0x80 >> i);	 // ��λ���浽�ֽ���
		} 
			                   
        
        SCL = 0;  // ʱ������
    }
    return byte;
}

/**
 * @brief ���� I2C Ӧ���ź�
 * @param ack Ӧ���źţ�0 ��ʾӦ��1 ��ʾ��Ӧ��
 * @retval ��
 */
void i2c_sendAck(unsigned char ack)
{
    SDA = ack;
    SCL = 1;
    SCL = 0;
}

/**
 * @brief ���� I2C Ӧ���ź�
 * @param ��
 * @retval ����Ӧ���źţ�0 ��ʾӦ��1 ��ʾ��Ӧ��
 */
unsigned char i2c_receiveAck(void)
{
    unsigned char ack;
    SDA = 1;  // �ͷ� SDA ��
    SCL = 1;  // ����ʱ��
    ack = SDA; // ��ȡӦ���ź�
    SCL = 0;  // ʱ������
    return ack;
}
