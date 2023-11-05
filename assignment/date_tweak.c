/*
 * time: 2022.10.24
 * privode:
 * issues：https://tieba.baidu.com/p/8100230549
 *         自动把日期改写成形如 2022-10-24 的形式
 *
 * solves: 占位符控制
 *         %*kc   可以跳过k个任何字符
 *         %02d   控制月数和天数是1~9时，在左边补0
 */
#include <stdio.h>

int main() {
    int year, month, day;
    scanf("%d%*c%d%*c%d", &year, &month, &day);  // valid by default

    if (year < 100) {
        year += 1900;  // 2-digit means the 20th century
    }

    printf("%d-%02d-%02d\n", year, month, day);

    return 0;
}

// 示例 输入 97/3.28      输出 1997-03-28