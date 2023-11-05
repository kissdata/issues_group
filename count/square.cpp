/*
 * time: 2022.11.03
 * privode:
 * issue: https://tieba.baidu.com/p/8118763148
 *        课程实验5 函数的参数传递第1题
 *
 * solve: 掌握C++的引用类型
 */
#include <iostream>
using std::cout;
using std::endl;

int f1(int, int&);
int f2(int);

int main() {
    int m;  // 待检查的三位数
    int x;  // 接收两位数

    for (m = 100; m < 1000; m++) {
        if (f1(m, x) && f2(m))
            cout << m << "=" << x << "^2" << endl;
    }

    return 0;
}

/** @brief  判断某个整型数是否满足: 是某个两位数的平方
    @param m int    输入的整型数
    @param x int&   带回的值
    @return [int]   是返回1不是就带回0
*/
int f1(int m, int& x) {
    int result = 0;  // 返回的d结果, 预设0
    int i;           // for的检索

    if (m < 10 * 10 || m > 99 * 99)  // 限制m
        return 0;

    // 平方数个位只能是 0 1 4 5 6 9
    int check[6] = {0, 1, 4, 5, 6, 9};
    for (i = 0; i < 6; i++) {
        if (m % 10 == check[i])
            break;
    }
    if (i == 6)  // 肯定不是平方数, 不再继续下去
        return result;

    // 假如 m=2022, i只要检查到45(=2025)就停
    for (i = 10; i * i < m + 1; i++) {
        if (i * i == m) {
            result = 1;
            x = i;
            break;
        }
    }

    return result;
}

/** @brief  判断某个整型数是否满足: 个位数、十位数、百位数各不相同且降序
    @param m int    输入的整型数
    @return [int]   是返回1不是就带回0
*/
int f2(int m) {
    int loc1 = m % 10;          // 个位数
    int loc10 = (m / 10) % 10;  // 十位数
    int loc100 = (m / 100);     // 百位数

    if (loc1 > loc10 && loc10 > loc100) {
        return 1;  // 比如129 , 数字越来越大才符合情况
    }

    return 0;
}

/* 输出结果
    169=13^2
    256=16^2
    289=17^2
*/