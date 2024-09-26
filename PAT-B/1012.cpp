/*
1012 数字分类
Score 20
Author CHEN, Yue
Organization 浙江大学

给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

    A1​ = 能被 5 整除的数字中所有偶数的和；
    A2​ = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1​−n2​+n3​−n4​⋯；
    A3​ = 被 5 除后余 2 的数字的个数；
    A4​ = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
    A5​ = 被 5 除后余 4 的数字中最大数字。

输入格式：

每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。
输出格式：

对给定的 N 个正整数，按题目要求计算 A1​~A5​ 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若分类之后某一类不存在数字，则在相应位置输出 N。
输入样例 1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例 1：

30 11 2 9.7 9

输入样例 2：

8 1 2 4 5 6 7 9 16

输出样例 2：

N 11 2 N 9

Code Size Limit
16 KB
Time Limit
400 ms
Memory Limit
64 MB
Stack size limit
8192 KB
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<int> v[5];
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x % 5].push_back(x);
    }
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    double a4 = 0;
    int a2_sign = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i == 0 && v[i][j] % 2 == 0)
                a1 += v[i][j];
            if (i == 1) {
                a2 += a2_sign * v[i][j];
                a2_sign *= -1;
            }
            if (i == 2)
                a3++;
            if (i == 3) 
                a4 += v[i][j];
            if (i == 4 && v[i][j] > a5)
                a5 = v[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (i != 0) 
            cout << " ";
        if (v[i].empty() || (i == 0 && a1 == 0))
            cout << "N";
        else if (i == 0)
            cout << a1;
        else if (i == 1)
            cout << a2;
        else if (i == 2)
            cout << a3;
        else if (i == 3)
            cout << fixed << setprecision(1) << a4 / v[3].size();
        else if (i == 4)
            cout << a5;
    }
    cout << endl;
}