#include <REGX52.H>
sbit SDA = P2^0;
sbit SCL = P2^1;

/**
 * @brief I2C开始信号
 * @param 无
 * @retval 无
 */
void i2c_start(void)
{
    SDA = 1;
    SCL = 1;
    SDA = 0;
    SCL = 0;
}

/**
 * @brief I2C结束信号
 * @param 无
 * @retval 无
 */
void i2c_stop(void)
{
    SDA = 0;
    SCL = 1;
    SDA = 1;
}

/**
 * @brief I2C发送一个字节
 * @param byte 要发送的字节
 * @retval 无
 */
void i2c_sendByte(unsigned char byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        SDA = (byte & (0x80 >> i));  // 从高位开始发送
        SCL = 1;                     // 发送数据时钟
        SCL = 0;                     // 时钟拉低
    }
}

/**
 * @brief I2C接收一个字节
 * @param 无
 * @retval 接收到的字节
 */
unsigned char i2c_receiveByte(void)
{
    unsigned char i, byte = 0;
    SDA = 1; // 释放 SDA 线
    for (i = 0; i < 8; i++)
    {
        SCL = 1;                     // 生成时钟
        if (SDA)                     // 读取 SDA 的值
        {
            byte |= (0x80 >> i);	 // 将位保存到字节中
		} 
			                   
        
        SCL = 0;  // 时钟拉低
    }
    return byte;
}

/**
 * @brief 发送 I2C 应答信号
 * @param ack 应答信号，0 表示应答，1 表示非应答
 * @retval 无
 */
void i2c_sendAck(unsigned char ack)
{
    SDA = ack;
    SCL = 1;
    SCL = 0;
}

/**
 * @brief 接收 I2C 应答信号
 * @param 无
 * @retval 返回应答信号，0 表示应答，1 表示非应答
 */
unsigned char i2c_receiveAck(void)
{
    unsigned char ack;
    SDA = 1;  // 释放 SDA 线
    SCL = 1;  // 生成时钟
    ack = SDA; // 读取应答信号
    SCL = 0;  // 时钟拉低
    return ack;
}
