/*
 * time: 2020.7.11
 * privode: QQ_2721689856   id: 白sheep树
 *
 * issues: 倒序输出冒泡排序后的数组内容
 *         冒泡排序：平均时间 O(n2) 稳定
 */
#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * 功能: 冒泡排序
 * 逻辑: 通过相邻的元素两两比较，不符合要求就交换位置
 */
void bubbleSort(int arr[], int n) {
  // i的次数比数组长度少1
  for (int i = 1; i < n; i++) {
    // i是从1开始的, n-i 无需再减1
    for (int j = 0; j < n - i; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);  // 大数排在前面
      }
    }
  }
}

int main(int, char**) {
  int shuzu[8] = {0};  // 定义时就要初始化，否则里面不用的位置都是垃圾值

  // 无占位符内容又结尾带\n的字符串，用puts函数更方便
  puts("请输入一串数字 (最多8个): ");

  // 数组下标，必须从0开始
  for (int i = 0; i < 8; i++) {
    scanf("%d", &shuzu[i]);
  }
  puts("");

  bubbleSort(shuzu, 8);  // 由大到小排序

  puts("排列后的数组为：");
  for (int i = 0; i < 8; i++) {
    printf("%d ", shuzu[i]);  // &是取地址，打印不用
  }
  printf("\n");

  return 0;
}

/*


*/