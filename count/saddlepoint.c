/*
 * time: 2022.11.28
 * provide: 桂林理工大学学妹
 * issues: 找出二维数组的鞍点: 在该行最大，在该列中最小; 也可能没有鞍点
 * 
 * e.g. 输入 3 4
 
    9   80   205   40
    90  -60  96    1
    210 -3   101   89
   -----------------------------------
    第2行第3列的 96 是鞍点

 * solves: 多重循环
 */
#include<stdio.h>
#define H 18
#define W 20

int main(){
    int a[H][W], value; // 存数据的数组和表示数组中每个元素的变量
    int m, n;           // 数组实际的行和列
    int max, maxj;      // 每行的最大值和此时的列坐标
    int i, k;
    int flag1, flag2; // 真假逻辑, 0或者1

    puts("输入行数和列数: "); // 单行显示的纯字符串提示语
    scanf("%d%d", &m, &n); getchar();
    for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++){
			scanf("%d", &value);
            a[i][k] = value; // 输入矩阵, 不熟悉就分开写
        }
        getchar();
	}
    puts("矩阵元素值: ");
    for (i = 0; i < m; i++) {
        for (k = 0; k < n; k++) printf("%5d", a[i][k]);
        putchar(10);
    }

    flag2 = 0; // 默认矩阵a[m][n]中无鞍点
    for(i = 0; i < m; i++){
        max = a[i][0]; // 假定每行第一个元素是这行最大的, 同时也是这一列最小的
        maxj = 0;
        for (k = 0; k < n; k++) { // 找最大值, 不能直接用maxj当作循环变量
            if (max < a[i][k]) {
                maxj = k;
                max = a[i][maxj]; 
            }
        }

        flag1 = 1; // 假定行里最大的max 也是列里最小的
        for (k = 0; k < m && flag1; k++) {
            if (a[k][maxj] < max) flag1 = 0; // 利用 && 省去了写break语句; 
        }
        if (flag1) {
            printf("\n第%d行第%d列的 %d 是鞍点\n", i + 1, maxj + 1, max);
            flag2 = 1;
        }
    }

    if (!flag2)
        puts("\n矩阵中无鞍点");
    return 0;
}