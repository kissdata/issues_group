/*
 * time: 2023.11.28
 * provider: subsibeibb
 *           东华理工大学
 *
 * issues: 求一批整数中出现最多的数字。
 *         输入n(1<n<1000), 再输入 n
 * 个整数，分析每个整数的每一位数字，求出现次数最多的数字。
 *
 * e.g.  输入 3
 *            1234 2345 3456
 *       输出 3 4
 *
 * solve:
 */

#include <stdio.h>
#include <stdlib.h>  // malloc
#include <string.h>

// 功能: 获取数组中最大的元素
int getMax(int *arr, int len) {
  int max = arr[0];
  for (int i = 1; i < len; i++) {
    if (max < arr[i]) max = arr[i];
  }
  return max;
}

// 功能: 显示数组里有相同值的元素
void displayMore(int *arr, int len, int x) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == x) printf("%d ", i);
  }
  printf("\n");
}

int main(int, char **) {
  int flag[10] = {0};  // 存每个数字字符出现的次数
  int n = 1;

  scanf("%d", &n);
  if (n < 1 || n > 1000) return 1;

  int *arr = NULL;
  arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  char number[12] = {0};
  for (int i = 0; i < n; i++) {
    // 将数组元素从整数转换为字符数组存储
    memset(number, 0, sizeof(number));
    sprintf(number, "%d", arr[i]);

    int len = strlen(number);
    int k;
    for (int j = 0; j < len; j++) {
      // 统计每次输入的数里每个数字字符出现的次数
      k = number[j] - '0';
      flag[k]++;
    }
  }

  // 把数字字符的数量最多的都显示出来
  int countMax = getMax(flag, 10);
  displayMore(flag, 10, countMax);

  return 0;
}
