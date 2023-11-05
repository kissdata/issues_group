/*
 * time: 2022.11.3
 * provider:
 * issue: https://tieba.baidu.com/p/8120939761
 *        字符串B在A中出现的次数, 如果A中有数字直接输出-1
 *
 * solve: 先用库函数isdigit判断有没有数字, 再用暴力法慢慢查找
 *
 */
#include <iostream>
#include <string>

using std::cin;   // 只包含3个常用标准库
using std::cout;  // 其他的库对象要用时再在名字加前缀std::
using std::endl;

int main() {
    int n;                   // 测试组的次数
    std::string A[5], B[5];  // string 来自std
    int lenA, lenB;          // 每组字符串AB的实际长度

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i];

    for (int i = 0; i < n; i++) {
        lenA = A[i].size();
        lenB = B[i].size();

        // 检测A中是否有数字
        int j = 0;  // 检索要在for作用域外声明, 因为后续要比较
        for (; j < lenA; j++)
            if (std::isdigit(A[i][j]))
                break;

        if (j < lenA) {
            cout << -1 << endl;  // 检索j在前面被打断过
            continue;
        }

        int count = 0;  // 存储B在A中的次数
        // 假如B有3个字符, 则A最后2个字符不用考虑
        for (int aj = 0; aj < lenA - (lenB - 1); aj++) {
            int bj = 0;  // 在for作用域外声明, 理由同上
            for (; bj < lenB; bj++)
                if (A[i][aj + bj] != B[i][bj])
                    break;

            if (bj == lenB) {
                count++;             // 检索bj在前面没有被打断过
                aj = aj + lenB - 1;  // 需要-1来抵消下一次for中的aj的自增
            }
        }
        cout << count << endl;
    }

    return 0;
}

/* 输入示例
    2
    abaababa
    aba
    aba123aba
    aba

   输出结果
    2
    -1
 */