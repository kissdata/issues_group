/* 
 * time: 2020.7.11  
 * privode: QQ_2721689856   id: 白sheep树
 * Comes from   Ways and Examples of C 338191797 
 * 冒泡排序：通过相邻的元素两两比较，不符合要求就交换位置
 * 		平均时间 O(n2) 稳定
 */

#include <stdio.h>

int main()
{
	int shuzu[8];
	int i, j, t;
	puts("请输入一串数字（最多8个）：");
	//无占位符内容又结尾带\n的字符串，用puts函数更方便
	for (i=0; i<8; i++)
		scanf("%d", &shuzu[i]);
	puts("\n接下来是倒序输出");
	for (i=1; i<8; i++)//i的次数比数组长度少1
		//for(j=0; j<7-i; j++)
		for(j=0; j<8-i; j++)//i是从1开始的
			if(shuzu[j]<shuzu[j+1])
			{
				t = shuzu[j];
				shuzu[j] = shuzu[j+1];
				shuzu[j+1] = t;
			}
	puts("排列后的数组为：");
	for (i=0; i<8; i++)		  // 数组下标，必须从0开始
		printf("%d ", shuzu[i]);  // &是取地址，打印不用
	printf("\n");
	return 0;
}
