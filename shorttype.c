/*
 * time: 2022.10.11
 * privode:
 * issues：https://tieba.baidu.com/p/8078314424
 *
 * solves: 占位符修改
 *         short类型占2字节, 用 %hd 格式控制符。只有输出可以都是 %d
 *
 * ps: 贴吧老哥误人子弟, 运行失败与赋值和程序自上而下的运行逻辑无关
 */
#include <stdio.h>

int main(void) {
    short int A, B, outSrc;  // 声明, 默认各为0, 但不能重复
    short out = A + B;
    // printf("%ld %ld\n", sizeof A, sizeof out);  // 2 2

    A = 1;
    scanf("%hd", &B);  // short类型
    printf("out=%d\n", out);
    outSrc = A + B;
    printf("outSrc=%hd\n", outSrc);

    return 0;
}

// 示例 输入 2   输出 out=0 outSrc=3

/* gdb调试命令
gcc shorttype.c -o program -g
gdb program --silent
b 14
run
c
q
*/