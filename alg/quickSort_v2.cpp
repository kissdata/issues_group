// time : 2024.8.30
#include <iostream>
#define MAXSIZE 9

using std::cin;
using std::cout;

// 带有排序核心功能的线性表类
class sqList {
 private:
  int length;
  int r[MAXSIZE + 1];

  int Partition(int, int);  // core

 public:
  sqList(int len) : length(len) {};
  ~sqList() {};

  void setArray();
  void showArray();
  void swap(int i, int j);

  friend void QSort(sqList *, int, int);
};

void sqList::setArray() {
  cout << "must input " << length << " number: ";
  for (int i = 1; i <= length; i++) cin >> r[i];
}

void sqList::showArray() {
  for (int i = 1; i <= length; i++) cout << r[i] << " ";
  putchar(10);
}

void sqList::swap(int i, int j) {
  int temp = r[i];
  r[i] = r[j];
  r[j] = temp;
}

// 带默认参数，减少顶层调用时候的参数
void QSort(sqList *L, int low = 1, int high = MAXSIZE) {
  int pivot;
  if (low < high) {
    pivot = L->Partition(low, high);
    QSort(L, low, pivot - 1);
    QSort(L, pivot + 1, high);
  }
}

int sqList::Partition(int low, int high) {
  int pivotkey = r[low];

  while (low < high) {
    while (low < high && r[high] >= pivotkey) high--;
    swap(low, high);

    while (low < high && r[low] <= pivotkey) low++;
    swap(low, high);
  }

  return low;
}

int main() {
  sqList *L = new sqList(MAXSIZE);
  L->setArray();

  QSort(L);

  L->showArray();
  return 0;
}