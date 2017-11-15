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
    matrix.begin(HT1632_COMMON_16NMOS);
    matrix.fillScreen();
    delay(500);
}

void loop()
{
    matrix.clearScreen();
    // 画一个像素点
    matrix.drawPixel(0, 0, 1);
    matrix.writeScreen();

    delay(500);
    // 清屏
    matrix.drawPixel(0, 0, 0);
    matrix.writeScreen();

    // 画一个矩形
    matrix.fillRect(matrix.width()/4, matrix.height()/4,
    matrix.width()/2, matrix.height()/2, 1);
    matrix.writeScreen();
    delay(500);

    // 画一个轮廓
    matrix.drawRect(0, 0, matrix.width(), matrix.height(), 1);
    matrix.writeScreen();
    delay(500);

    // 画一个红色的'X'
    matrix.clearScreen();
    matrix.drawLine(0, 0, matrix.width()-1, matrix.height()-1, 1);
    matrix.drawLine(matrix.width()-1, 0, 0, matrix.height()-1, 1);
    matrix.writeScreen();
    delay(500);

    // 画一个圆
    matrix.fillCircle(matrix.width()/2-1, matrix.height()/2-1, 7, 1);
    matrix.writeScreen();
    delay(500);

    matrix.drawCircle(matrix.width()/2-1, matrix.height()/2-1, 4, 0);
    matrix.writeScreen();
    delay(500);

    matrix.clearScreen();
    // 显示文字
    matrix.setTextSize(1);
    matrix.setTextColor(1);

    if (matrix.width() <= 24)
    {
        matrix.setCursor(0, 0);
        matrix.print("Adaf ");
        matrix.setCursor(0, 8);
        matrix.print("ruit");
        matrix.writeScreen();
    }
    else if (matrix.width() > 24)
    {
        matrix.setCursor(0, 0);
        matrix.print("Adafruit");
        matrix.setCursor(0, 8);
        matrix.print("Industr.");
        matrix.writeScreen();
    }
    delay(2000);
}
