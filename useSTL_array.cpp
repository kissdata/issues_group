/*
 * time: 2022.11.25
 * issues: https://tieba.baidu.com/p/8153709331
 *         exp7.10 销售人员薪资范围, 统计每个范围内满足条件的有多少人
 * 
 * solve: 利用一个计数器的array对象
 */
#include<iostream>
#include<random>
#include<iomanip>
#include<array>  // 顺序容器 静态数组

using std::cout;
using std::endl;
using std::array;

const int N = 26; // 假定员工规模

// 给每个员工假定销售额, 随机在(a, b)区间
void InitArr(array<int, N> &arr, int a, int b){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> di(a, b);
    for (array<int, N>::iterator i = arr.begin(); i != arr.end(); i++)
        *i = di(engine);
}

int main(){
    array<int, N> staff;     // 所有员工的销售额
    array<int, 9> status{0}; // 报酬范围的9种情形
    InitArr(staff, 0, 9999);

    cout << "Sales: ";
    for (auto e : staff)
        cout << std::setw(6) << e;
    cout << endl;
    
    cout << "Wages: "; 
    for (int i = 0; i < staff.size(); i++) {
        int wage = staff.at(i) * 9 / 100 + 200; // 实际工资 = 9%提成+200底薪
        cout << std::setw(6) << wage;
        if (wage < 1000)
            status[wage/100-2]++;
        else
            status[8]++;
    }

    for (int i = 2; i < 10 ; i++) 
        cout << endl << i << "00~" << i << "99 美元: "<< status.at(i-2);
    cout << endl << "1000 美元及以上: " << status[8] << '\n';

    return 0;
}
