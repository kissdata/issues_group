/*
 * time: 2023.11.24
 * privode: 格物数安实习
 * issue: 列出给定字符串所有的子字符串
 *
 * solve: 1 直接输出对应位置的字符，输出到指定长度就停止
          2 复制到新字符串输出，指定位置加 \0
 */

#include <stdio.h>
#include <string.h>

// 功能: 输出字符数组一部分
void inputPart(const char* str, int start, int len);

// 功能: 子串用新的字符数组存储
void inputPart2(const char* str, int start, int len);

int main(int, char**) {
  char str[10] = {'0'};
  scanf("%s", str);
  int Len = strlen(str);
  // printf("%d %s\n", Len, str);

  for (int i = 0; i < Len; ++i) {
    for (int j = 1; j < Len - i + 1; ++j) {
      inputPart2(str, i, j);
    }
  }

  return 0;
}

void inputPart(const char* str, int start, int len) {
  for (int i = 0; i < strlen(str); ++i) {
    if (i == len) {
      break;
    }
    printf("%c", str[i + start]);
  }
  printf("\n");
}

void inputPart2(const char* str, int start, int len) {
  char tmpArr[80];
  strcpy(tmpArr, str);
  char* p = tmpArr;

  // 在特定子串末尾加0截断
  p[start + len] = '\0';
  p = p + start;
  printf("%s\n", p);
}
