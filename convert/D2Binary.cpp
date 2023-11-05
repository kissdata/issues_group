/*
 * time: 2022.11.24
 * 
 * issues: 十进制转为二进制, 得到的内容顺序是反的
 * 
 * solves: 用数组存储二进制形式的倒序, 从后往前打印
 * 
 */
#include <iostream>
using std::cout;

// 功能: 十进制转二进制
void D2Binary(int m) {
    int arr[33] = {0}, *p = arr;
    for (int i = 1; i < 32; i++)
        arr[i] = 2;

    while (m) {
        *p++ = m % 2;
        m >>= 1; // 右移一位, 相当于 m/=2;
    }
    for (int i = 0; arr[i] != 2; i++)
        cout << *(p - i - 1); // 指针在有效值之后, 要再往前一下
}

int main() {
    int m;
    std::cin >> m;
    D2Binary(m);

    return 0;
}