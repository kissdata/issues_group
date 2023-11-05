/*
 * time: 2022.10.30
 * privode:
 * issues: https://tieba.baidu.com/p/8110830010
 *         输入年份和月份, 输出该年月的日历
 *
 * e.g. 输入 2020 4

   -----------------------------------
     Mon  Tue  Wed  Thu  Fri  Sat  Sun
                 1    2    3    4    5
       6    7    8    9   10   11   12
      13   14   15   16   17   18   19
      20   21   22   23   24   25   26
      27   28   29   30
   -----------------------------------

 * solve: 先获得这个月的第一天，再按序输出所有天数
 *
 */
#include <stdio.h>

int leapYear(int);          // 判断闰年
int whatDay(int, int);      // 计算某年某月的1号是星期几
void printMonth(int, int);  // 按要求的格式打印某年某月的日历

int monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
    int y, m;  // 接收用户的输入年和月
    int firstday;

    puts("Please enter the year and month:");
    scanf("%d%d", &y, &m);
    if (y < 1 || m < 1 || m > 12)
        return 0;

    firstday = whatDay(y, m);
    printMonth(m, firstday);

    return 0;
}

/** @brief 判断闰年
    @param y  目标年份
*/
int leapYear(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
        return 1;  // 1表示是闰年, 366天
    return 0;
}

/** @brief    计算某年某月的1号是星期几
    @param destyear  目标年份
    @param destmonth 目标月份
*/
int whatDay(int destyear, int destmonth) {
    int year, month;
    int day = 1;  // 用来表示1号是周几

    if (leapYear(destmonth) && monthdays[2] != 29)
        monthdays[2] = 29;  // 纠正2月默认天数

    /* 输入年的1月1号的星期几 */
    for (year = 1; year < destyear; ++year)
        if (leapYear(year)) {
            day = (day + 366) % 7;  // 闰年366
        } else {
            day = (day + 365) % 7;
        }

    /* 输入月的1号是周几 */
    for (month = 1; month < destmonth; ++month)
        day = (day + monthdays[month]) % 7;

    return day;
}

/** @brief    打印该年该月的日历, 要求:每个星期几占5个字节, 右对齐
    @param month     需要打印的月份
    @param firstday  1号是周几
*/
void printMonth(int month, int firstday) {
    int i, day;
    // printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n") // 不用该方法, 太low

    // 至少4, 留一个存放 \0
    char weekname[][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    for (i = 0; i < 7; i++)
        printf("%5s", weekname[i]);
    putchar('\n');

    day = firstday % 7;  // 预防其他地方调用时输入>7的数
    for (i = 0; i < (day - 1) * 5; i++)
        putchar(' ');  //在第一天前面增加前几天的空格

    // 这里省略纠正2月默认天数, 因为前面已经在调用其他函数时纠正
    for (i = 1; i < monthdays[month] + 1; ++i) {
        printf("%5d", i);
        if (++day % 7 == 1)
            putchar('\n');  // 一行7天, 超过时另起一行
    }
    putchar('\n');
}
