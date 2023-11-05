/*
 * Time: 2020.7.11
 * provider: QQ_1295753615 米洛
 *
 * issues：写统计功能的函数，有EOF的情况下不知道输入内容后怎么停止
 *
 * solves: Ctrl-D 是一个特殊的二进制值，表示EOF
 *         Ctrl-Z 是中断命令，不会显示输出结果
 */

#include <ctype.h>  //调用统计功能的库函数
#include <stdio.h>

int main(int, char**) {
  int c;
  int cd = 0, cu = 0, cl = 0;
  while ((c = getchar()) != EOF)  // 先按Enter，再Ctrl + D结束输入
  // while((c=getchar()!='\n')  顺序读入一行，遇到Enter换行结束输入
  {
    if (isdigit(c)) ++cd;
    if (isupper(c)) ++cu;
    if (islower(c)) ++cl;
  }
  /* is~() 统计文件中数字、大小写字母的个数
   * 采用标准库的函数比自己写条件更合适
   */
  printf("disits: %d\tuppers: %d\tlowers: %d\n", cd, cu, cl);

  return 0;
}

/**
 * getchar()返回值类型是int
 *
 * getchar()函数好处：解决了输入规范的问题
 * 	getchar相当于调整Enter键入的换行字符数量
 *      因为在含有变量为char的情况下，用户的Enter键输进去的换行符被接收
 *      编译器规定输入的时候不立即回显，而是存到1个缓冲区，当遇到Enter的
 *      换行字符时候才会一次性释放缓冲区里的数据并且清空缓冲区
 */
