/*
 * time: 2022.11.01
 * privode:
 * issue: https://tieba.baidu.com/p/8113017670
 *        字符串中的字符能组成多少个 IGNB, 每个字符只输出一次
 *
 * e.g.   输入 isdfsBgNgdnssibb  输出 IGNBIGNB
 */
#include <stdio.h>
#include <string.h>  //strchr

void Upwrite(char*);

void findIGNB(char*, char*);

int main(int, char**) {
  char srcInput[1000];
  scanf("%s", srcInput);

  findIGNB(srcInput, "IGNB");

  return 0;
}

// 功能: 利用给出的字符串能组成多少个IGNB
void findIGNB(char* str, char* dest) {
  int count[1000] = {0};  // 按照ignb顺序存储各自数量
  int min;                // 用于存放最小值
  int i;
  char* p;

  // step1 待查字符串统一成大写字母
  Upwrite(str);

  // step2 统计检测串每个字符在原串中的的个数
  p = str;
  while (*p) {
    for (i = 0; i < 4; i++) {
      if (dest[i] == *p) count[i]++;
    }
    p++;
  }

  // step3 找出数组元素中的最小值
  min = count[0];
  for (i = 0; i < 4; i++) {
    if (count[i] < min) min = count[i];
  }

  // step4 输出所有的IGNB
  if (min == 0) {
    puts("There is no NB!");
  } else {
    for (i = 0; i < min; i++) printf("%s", dest);
    printf("\n");
  }
}

void Upwrite(char* str) {
  char* p = str;
  while (*p != '\0') {  // 也可不用p, 直接 while(*src)
    if (*p >= 'a' && *p <= 'z') *p -= 32;
    p++;
  }
}