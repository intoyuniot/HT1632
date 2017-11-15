/*
该例程展示如何控制HT1632(可以被使用在16x24 LED矩阵屏)
硬件连接:
HT1632 使用三线控制
date  -  数据引脚
wr    -  写入控制引脚
cs     -  片选引脚
多个HT1632控制, 可以使用相同的data和write引脚.但需要不同的CS脚.
*/
#include <HT1632.h>

#define DATA D2
#define WR   D3
#define CS   D4

HT1632 matrix = HT1632(DATA, WR, CS);

void testMatrix(HT1632 matrix)
{
    for (int i=0; i<24*16; i++)
    {
        matrix.setPixel(i);
        matrix.writeScreen();
    }
    // 闪屏
    matrix.blink(true);
    delay(2000);
    matrix.blink(false);

    // 亮度逐渐下降
    for (int8_t i=15; i>=0; i--)
    {
        matrix.setBrightness(i);
        delay(100);
    }
    // 亮度逐渐上升
    for (uint8_t i=0; i<16; i++)
    {
        matrix.setBrightness(i);
        delay(100);
    }
    // 清屏
    for (int i=0; i<24*16; i++)
    {
        matrix.clrPixel(i);
        matrix.writeScreen();
    }
}


void setup()
{
    matrix.begin(HT1632_COMMON_16NMOS);
    delay(100);
    matrix.clearScreen();
}

void loop()
{
    testMatrix(matrix);
}
