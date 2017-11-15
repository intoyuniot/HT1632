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

#define DATA 2
#define WR   3
#define CS   4
#define CS2  5

// 单个点阵
HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);
// 两个点阵
//HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS, CS2);

void setup()
{
    SerialUSB.begin(115200);
    matrix.begin(HT1632_COMMON_16NMOS);
    matrix.fillScreen();
    delay(500);
    matrix.clearScreen();
}

void loop()
{
    for (uint8_t y=0; y<matrix.height(); y++)
    {
        for (uint8_t x=0; x< matrix.width(); x++)
        {
            matrix.setPixel(x, y);
            matrix.writeScreen();
        }
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

    for (uint8_t y=0; y<matrix.height(); y++)
    {
        for (uint8_t x=0; x< matrix.width(); x++)
        {
            matrix.clrPixel(x, y);
            matrix.writeScreen();
        }
    }
}
