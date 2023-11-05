/*
 * time: 2022.10.26
 * privode:
 * issues: https://tieba.baidu.com/p/8102785675
 *         打印如下的星号图形

    --------------------------------------------------------
    *              **********      **********              *
    **             *********        *********             **
    ***            ********          ********            ***
    ****           *******            *******           ****
    *****          ******              ******          *****
    ******         *****                *****         ******
    *******        ****                  ****        *******
    ********       ***                    ***       ********
    *********      **                      **      *********
    **********     *                        *     **********
    --------------------------------------------------------

 * solves: 多种方法。
 *         display1  直接打印
 *         display2  偏向划分成多个矩形，一行一行打印
 *         display3  从三角形角度考虑, 部分空矩形用占位符代替
 *         display4  对折, 存入数组。TODO
 */
#include <stdio.h>

void display1();

void display2() {
    int row;  // 表示行号
    int numberStar;  // 表示一个矩形内的星星数量, 用于计算和row的关系
    int numberSpace;  // 表示一个矩形内的空数量, 用于计算和row的关系
    int width;  // 表示空矩形的宽度
    int j;

    for (row = 0; row < 10; row++) {
        //*** 实现第1个矩形
        numberStar = row + 1;  // 直角星星三角形的每行数量关系式
        for (j = 0; j < numberStar; j++) {
            printf("*");
        }
        numberSpace = 10 - numberStar;  // 直角空三角形的每行数量关系式
        for (j = 0; j < numberSpace; j++) {
            printf(" ");
        }

        width = 5;  // 实现第2个矩形(间隙空矩形)
        for (j = 0; j < width; j++) {
            printf(" ");
        }

        //*** 实现第3个矩形
        numberStar = 10 - row;
        for (j = 0; j < numberStar; j++) {
            printf("*");
        }
        numberSpace = 10 - numberStar;
        for (j = 0; j < numberSpace; j++) {
            printf(" ");
        }

        width = 6;  // 实现第4个矩形(间隙空矩形)
        for (j = 0; j < width; j++) {
            printf(" ");
        }

        //*** 实现第5个矩形
        for (j = 0; j < row; j++) {  // numberSpace = row 简写, 下同
            printf(" ");
        }
        for (j = 0; j < 10 - row; j++) {
            printf("*");
        }

        width = 5;  // 第6个矩形(间隙空矩形)
        for (j = 0; j < width; j++) {
            printf(" ");
        }

        //*** 实现第7个矩形
        for (j = 0; j < 9 - row; j++) {
            printf(" ");
        }
        for (j = 0; j < row + 1; j++) {
            printf("*");
        }

        printf("\n");  // 一行
    }
}

// display2的改良
void display3() {
    int row;
    int j;

    for (row = 0; row < 10; row++) {
        for (j = 0; j < row + 1; j++) {
            printf("*");
        }
        for (j = 0; j < 9 - row; j++) {
            printf(" ");
        }
        printf("%5s", " ");  // 间隙为5

        for (j = 0; j < 10 - row; j++) {
            printf("*");
        }
        for (j = 0; j < row; j++) {
            printf(" ");
        }
        printf("%6s", " ");  // 间隙为6

        for (j = 0; j < row; j++) {
            printf(" ");
        }
        for (j = 0; j < 10 - row; j++) {
            printf("*");
        }
        printf("%5s", " ");  // 间隙为5

        for (j = 0; j < 9 - row; j++) {
            printf(" ");
        }
        for (j = 0; j < row + 1; j++) {
            printf("*");
        }

        printf("\n");
    }
}

int main(void) {
    // display1();
    // display2();

    display3();

    return 0;
}

void display1() {
    printf("*              **********      **********              *\n");
    printf("**             *********        *********             **\n");
    printf("***            ********          ********            ***\n");
    printf("****           *******            *******           ****\n");
    printf("*****          ******              ******          *****\n");
    printf("******         *****                *****         ******\n");
    printf("*******        ****                  ****        *******\n");
    printf("********       ***                    ***       ********\n");
    printf("*********      **                      **      *********\n");
    printf("**********     *                        *     **********\n");
}