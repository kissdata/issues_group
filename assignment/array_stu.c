/*
 * time:  2020.7.8
 * provide: QQ_675284858 Comes From Revolution C-language-2
 *
 * discribe：输出学生的3门分数，和科目对应，科目名不再另外存储
 *           使用字符数组存储名字
 */

#include <stdio.h>

typedef struct {
  int sno;
  char name[10];
  char classN[20];
  int score[3];
} student;

int main(void) {
  int i;
  student stu[3] = {{1001, "李萍", "计科1701", 90, 92, 98},
                    {1002, "李萍", "计科1701", 88, 80, 89},
                    {1003, "李萍", "计科1701", 85, 82, 78}};

  for (i = 0; i < 3; i++)
    printf("%d %s %s:\t语文\t数学\t英语\n\t\t\t %d\t %d\t %d\n\n", stu[i].sno,
           stu[i].name, stu[i].classN, stu[i].score[0], stu[i].score[1],
           stu[i].score[2]);

  return 0;
}
