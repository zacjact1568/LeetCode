//
// Created by Zack Zhang on 2018/9/19.
//

#include "ReverseInteger.h"

int ReverseInteger::solution(int x) {
    // 10 位数 + 1 位结束标志
    // 32 位有符号数绝对值的十进制最多 10 位（2^31-1）
    int digit[11];
    // 商初始化为 x 的绝对值
    int quotient = x < 0 ? -x : x;
    // x 是否负数
    bool isNegative = x < 0;
    int i = 0;
    while (quotient != 0) {
        // 余数
        digit[i++] = quotient % 10;
        quotient /= 10;
    }
    // 结束标志
    digit[i] = -1;
    int result = 0;
    int temp;
    bool isOverflow;
    for (int d : digit) {
        if (d == -1) break;
        temp = result * 10;
        // 检查乘法是否溢出
        isOverflow = temp / 10 != result;
        result = isOverflow ? 0 : temp;
        // 若溢出，退出循环
        if (isOverflow) break;
        temp = result + d;
        // 检查加法是否溢出
        result = temp < 0 ? 0 : temp;
    }
    // 如果 x 是负数，取相反数
    if (isNegative) {
        result = -result;
    }
    return result;
}

void ReverseInteger::test() {
    ReverseInteger ri;
    ri.solution(-123);
}
