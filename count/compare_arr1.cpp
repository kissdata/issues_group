/*
 * time:  2022.10.4
 * provide: QQ_1704834159 Comes From Revolution C-language-2
 *
 * issues：老师让他讲同学写的代码, 他看不懂。想要群友帮忙解释一下, 只要注释
 * solve: 无。
 *        '风轻'(西安 QQ_1812256028) 能解决, 但要100元才给他每行加注释
 *
 * discribe：查找类型题解。输入两个字符串, 特色的匹配方式, 找到相等时的结果
 *
 */
#include <cstring>
#include <iostream>
using namespace std;

int flag, src, resultFind;

// 功能:
int whatbase(char arr[], int n) {
  int t = 0, y = 0;

  for (int i = 0; i < strlen(arr); i++) {
    // ASCII码运算
    if (arr[i] >= '0' && arr[i] <= '9')
      t = arr[i] - '0';  // 将数字字符转换成实际数字, 例 '8' -> 8

    // 第2次调用，将将A(65)之后的字符转换, 例 'B' - > 11
    // 随着n增大, 起始字符从A往后推移
    else if (n >= 11 && (arr[i] >= 'A' + n - 10))
      t = arr[i] - 'A' + 10;  //

    y = y * n + t;  // 方程 y = nx + t
  }
  return y;
}

int main() {
  char xArr[1001], yArr[1001];  // 数组加 Arr后缀
  int left, right;

  puts("输入使用算法的次数: ");  // 将 每个cin 的输入意图和输出结果打出来
  int k;
  cin >> k;
  cout << "即将测试" << k << "次程序" << endl;

  while (k != 0) {
    k--;
    cout << "测试1次, 输入两个字符数组: ";

    cin >> xArr >> yArr;
    for (int i = 10; i <= 15000; i++) {
      src = whatbase(xArr, i);
      cout << "第1个字符数组" << xArr << "调用函数后的结果: " << src << endl;

      left = 10, right = 15000;
      while (left <= right) {
        int mid = left + (right - left) / 2;  // 二分

        resultFind = whatbase(yArr, mid);
        cout << "第2个字符数组" << yArr << "调用函数后的结果: " << resultFind
             << endl;
        if (resultFind == src) {
          cout << "查找成功, i= " << i << " mid= " << mid << endl;
          break;
        } else if (resultFind < src)
          left = mid + 1;
        else
          right = mid - 1;
      }
      if (src == resultFind) break;
      cout << "没有获得相等值, 开始第" << i - 8 << "轮查找\n";
    }
  }
}

// 示例1 输入 a  v   输出 i=10 mid-7505
// 示例2 输入 8A 3c  输出 i=12 mid=20

/**
 * 经验:

 1. 全局变量不滥用，鼠标放到变量名上，如果只在单函数中使用的，移入函数中
 2. 代表字数的变量就是 串长strlen(length of string), 没有其他处理不应该另设变量
 3. QQ_3153079281：最好是让写代码的人讲, 他才知道为什么要这么写:
        有哪些小细节, 一些特殊或者边界情况他怎么考虑和处理的, 这些才是关键。
*/

// ------------------------ 原shi代码 ----------------------------------
/*
#include<bits/stdc++.h>
using namespace std;

int k,flag,yyf,QWQ,l,r,AWA,i,t,zishu;
int whatbase(char a[],int n)
{
        zishu=strlen(a);
        AWA=0;
        for(int i=0; i<zishu; i++){
                if(a[i]>='0'&&a[i]<='9') t=a[i]-'0';

                else if (n>=11&&(a[i]>='A'+n-10)) t=a[i]-'A'+10;
                AWA=AWA*n+t;
        }
        return AWA;
}

int main()
{
        char x[1001],y[1001];
        cin>>k;
        while(k!=0)
        {
                k--;
                cin>>x>>y;
                for(int i=10; i<=15000; i++)
                {
                        yyf=whatbase(x,i);
                        l=10,r=15000;
                        while(l<=r)
                        {
                                int mid=(l+r)/2;
                                QWQ=whatbase(y,mid);
                                if(QWQ==yyf){cout<<i<<" "<<mid<<endl; break;}
                                else
                                        if(QWQ<yyf)
                                                l=mid+1;
                                else
                                        r=mid-1;
                        }
                        if(yyf==QWQ) break;
                }
        }
}

*/