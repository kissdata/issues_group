/**
 * Time: 2020.7.12 
 * provide: me  Comes from Revolution C-language 2
 * solve: 伤痛IV QQ_1744128119
 *
 * describe: 输入什么，就输出和是它的全部连续字串
 *           输入 10  输出 1234
 *           输入 13  输出 67
 *           输入 15  输出 12345、456、78
 *
 */

#include <stdio.h>
#include <stdlib.h>

void fun(int num)
{
	int i,j,k,m,s;
	for(j=(int)((num/2)+2); j>0; j--)//begain number
	{
		for(k=j,s=0;k>0;k--)//temp number
		{												s+=k;
			if(s==num)
			{
				for(m=k; m<=j; m++)
					printf("%d,",m);
				printf("\n");
				break;
			}
			if(s>num)
					break;
		}
	}
}

int main( )
{
	int num;
	printf("输入数 x = ");
	scanf("%d",&num);
	fun(num);
	
	return 0;
}
