/**
 * time: 2022.12.19
 * issues: 输入一行字符串, 连续出现的数字当作一个整数, 统计有多少个整数
 * 
 * e.g. 输入 df23adfd56 2343? 23dgjop535
 *      输出 5
 *           23 56 2343 23 535
 * 
 * solve: 两种思路，一个是边插入边运算，另一个是插入完成后再运算。提供3中处理方法
 *        方法1 边输入边运算, 数组存储各个整数
 *        方法2 输入完后处理整个字符串，对每个整数头尾插旗
 *        方法3 输入完后处理整个字符串，将非数字字符换成空格，并剪除多余空格
*/
#include<iostream>
#include<string>
#define MAX 80

using std::cin;
using std::cout;
using std::string;

void Way_v1(void);
void Way_v2(const string &src);
void Way_v3(string &src);

int main() {
    string src;
    std::getline(cin, src);
    // Way_v1();
    // Way_v2(src);
    Way_v3(src);

    return 0;
}

void Way_v1() {
    int arr[MAX] = {0}; // 用来存放整数的数组
    int i, countDigit; // 数组下标和专门统计数字连续量

    countDigit = 0;
    i = -1;
    for (int c = 0; c = std::getchar(); c = 0) {
        if (c == '\n')
            break;
        if(c < 0x30 || c > 0x39) {
            countDigit = 0;
            continue; 
        }
        if (++countDigit == 1)  i++;

        arr[i] = arr[i] * 10 + (c - 48);             
    } 

    cout << i + 1<< "\n";
    for (int x = 0; x < i + 1; x++) cout << arr[x] << " ";
    cout << "\n";
}

void Way_v2(const string &src) {
    int head[MAX] = {0}, tail[MAX] = {0};
    char substr[MAX];
    int flag = 0;

    // 确定每个整数的起始点位置, 第一个元素要要另外判断
    if (src[0] >= '0' && src[0] <= '9')  head[flag++] = 0; 
    for (int i = 1; i < src.size(); i++)
        if ((src[i] >= 0x30 && src[i] <= 0x39) && (src[i - 1] < 0x30 || src[i - 1] > 0x39))
            head[flag++] = i;

    // 确认每个整数的结尾位置, 同样最后一个元素需要额外判断
    flag = 0;
    int i = 0; // 定义在外面，方便后面直接表示最后一个元素 
    for ( ; i < src.size() - 1; i++)
        if (src[i] >= 0x30 && src[i] <= 0x39 && (src[i + 1] < 0x30 || src[i + 1] > 0x39))
            tail[flag++] = i + 1;
    // i == size - 1
    if (src[i] >= '0' && src[i] <= '9')  tail[flag++] = src.size(); 

    cout << flag << "\n";
    for (int i = 0; i < flag; i++) {
        int sublen = src.copy(substr, tail[i] - head[i], head[i]);
        substr[sublen] = '\0';
        // 转换处理, 防止 0026 这种
        cout << std::strtol(substr, nullptr, 10) << " ";
    }
    cout << "\n";
}

void Way_v3(string &src) {
    for (int i = src.size() - 1; i > 0; i--)
        if (src[i] < '0' || src[i] > '9') {
            if (src[i - 1] < '0' || src[i - 1] > '9')
                src.erase(i, 1);
            else
                src[i] = ' ';
        }

    src.erase(src.find_last_not_of(32) + 1);
    src.erase(0, src.find_first_not_of(32));

    int total = 0;   
    for (auto x:src)  if (x == ' ') total++;
    
    cout << 1 + total << "\n";
    cout << src << "\n";
}