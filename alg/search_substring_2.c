/**
 * Time: 2020.7.12
 * provide: me  Comes from Revolution C-language 2
 * solve: 'Warrior of the Night' QQ_2210086948
 *        intro: 深圳大学 软件学院2019级 本科
 *
 * describe: 输入什么，就输出和是它的全部连续字串
 */
#include <stdbool.h>
#include <stdio.h>
//使用滑动窗口

void printRange(int x, int y) {
    int i;
    for (i = x; i <= y; i++)
        printf("%d", i);
    printf("\n");
}

void find(int x) {
    int i, j;
    int sum = 0;
    i = j = x / 2 + 1;
    sum += i;
    // true 不是C语言的关键字，是预处理宏，必须加头文件<stdbool.h>
    while (true) {
        if (i < 1)
            break;
        if (sum < x)
            i--, sum += i;
        else if (sum > x)
            i--, sum += i, sum -= j, j--;
        else {
            // sum == x;
            printRange(i, j);
            i--, sum += i, sum -= j, j--;
        }
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