/**
 * time: 2024.8.30
 * privode: 贴吧 XixiLq
 *
 * issues: 使用线性表指针前没有定义实体
 */
#include <stdio.h>
#define MAXSIZE 9

typedef struct {
  int r[MAXSIZE + 1];
  int length;
} SqList;

// core
int Partition(SqList *, int, int);

void swap(SqList *L, int i, int j) {
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}

/**
 * 功能：快排
 * 逻辑：递归
 */
void QSort(SqList *L, int low, int high) {
  int pivot;
  if (low < high) {
    pivot = Partition(L, low, high);
    QSort(L, low, pivot - 1);
    QSort(L, pivot + 1, high);
  }
}

int main(void) {
  SqList *L;
  SqList instanceL;  // must
  L = &instanceL;

  L->length = MAXSIZE;
  for (int i = 1; i <= MAXSIZE; i++) scanf("%d", &L->r[i]);

  QSort(L, 1, L->length);
  for (int i = 1; i <= MAXSIZE; i++) printf("%d ", L->r[i]);

  putchar(10);
  return 0;
}

int Partition(SqList *L, int low, int high) {
  int pivotkey = L->r[low];

  while (low < high) {
    while (low < high && L->r[high] >= pivotkey) high--;
    swap(L, low, high);

    while (low < high && L->r[low] <= pivotkey) low++;
    swap(L, low, high);
  }

  return low;
}
