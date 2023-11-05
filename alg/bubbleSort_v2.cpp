/*
 * time: 2022.11.24
 * 
 * issues: 取随机数, C语言只能srand rand, C++11带了random库
 * 
 * reference: https://en.cppreference.com/w/cpp/header/random
 */
#include<iostream>
#include<random>
using std::cout;

// 功能: 给数组的每个元素赋值随机数
// 逻辑: C++的取随机数固定写法, 选用平均分布
void InitHeapArr(int *arr, int n){
    std::random_device rd; 
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> di(999, 11111); // 数值区间
    for (int i = 0; i < n; i++)
        *(arr+i) = di(engine);
}

// 功能: 冒泡方法排序
void bubbleSort(int *arr, int n){
    int temp;
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) {
            // 交换
            if (arr[j] > arr[j+1]) {
                temp = arr[j], arr[j] = arr[j+1], arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n = 20;
    int *pArr = new int[n]; // 堆上开数组, 最好用智能指针
    InitHeapArr(pArr, n);   // 赋值随机数

    for (int i = 0; i < n; i++) cout << pArr[i] << " "; // 排序前
    putchar(10);

    bubbleSort(pArr, n);

    for (int i = 0; i < n; i++) cout << pArr[i] << " "; // 排序后
    putchar(10);

    delete[] pArr; // 堆指针收尾
    return 0;
}