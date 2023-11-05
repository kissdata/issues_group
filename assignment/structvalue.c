#include <stdio.h>
/* 
 * provide: QQ_675284858   Comes From Revolution C-language 2
 * 
 * discribe: 结构体中使用了结构体，如何初始化
 */

typedef struct People{
	int id;
	int group;
}People;

typedef struct Tool{
	People man;
	char name[8];
}Tool;

int main()
{
	Tool car= {
		{2,3},
		"汽车"
	};
	printf("正在使用%s的是%d小组的%d号成员。\n", car.name, car.man.group, car.man.id);

	return 0;
}
