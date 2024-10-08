/*
1011 A+B 和 C
Score 15
Author HOU, Qiming
Organization 浙江大学

给定区间 [−231,231] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。
输入格式：

输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。
输出格式：

对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。
输入样例：

4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647

输出样例：

Case #1: false
Case #2: true
Case #3: true
Case #4: false

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
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        if (a + b > c) {
            cout << "Case #" << i << ": true" << endl;
        } else {
            cout << "Case #" << i << ": false" << endl;
        }
    }
    return 0;
}