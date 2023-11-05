/**
 * Time: 2020.7.12
 * provide: me  Comes from Revolution C-language 2
 * solve: '伤痛IV' QQ_1744128119
 *
 * describe: 输入什么，就输出和是它的全部连续字串
 */
#include <stdio.h>
#include <stdlib.h>

// 思路: 从中间数开始数，从大到小依次相加
void fun(int num) {
    int i, k;
    int sum;  // 统计已叠加的和
    int begin = (int)((num / 2) + 2);

    while (begin > 0) {
        for (k = begin, sum = 0; k > 0; k--) {
            sum += k;

            // 如果叠加的和正好, 打印此时加过的数
            if (sum == num) {
                for (i = k; i < begin; i++)
                    printf("%d,", i);
                printf("%d\n", begin);  // 结尾数另外写, 防止尾部多余逗号
                break;
            }
            if (sum > num) {
                break;
            }
        }
        begin--;
    }
}

int main(void) {
    int num;
    do {
        printf("输入正整数x=");
        scanf("%d", &num);

        find(num);

        if (num)
            puts("----- 按 0 退出程序 -----");
    } while (num != 0);

    return 0;
}

// 示例1  输入 10    输出 1234
// 示例2  输入 13    输出 67
// 示例3  输入 15    输出 12345、456、78
