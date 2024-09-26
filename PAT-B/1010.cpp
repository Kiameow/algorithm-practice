/*
1010 一元多项式求导
Score 25
Author DS课程组
Organization 浙江大学

设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为nxn−1。）
输入格式:

以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。
输出格式:

以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。
输入样例:

3 4 -5 2 6 1 -2 0

输出样例:

12 3 -10 1 6 0

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

using namespace std;

vector<pair<int, int>> diff(vector<pair<int, int>> poly) {
    vector<pair<int, int>> res;
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i].second == 0) {
            continue;
        }
        res.push_back(make_pair(poly[i].first * poly[i].second, poly[i].second - 1));
    }
    return res;
}

int main() {
    int coef, exp;
    vector<pair<int, int>> poly;
    while (cin >> coef >> exp) {
        poly.push_back(make_pair(coef, exp));
    }
    poly = diff(poly);
    bool first = true;
    if (poly.empty()) {
        cout << "0 0" << endl;
    } else {
        for (auto p : poly) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << p.first << " " << p.second;
        }
        cout << endl;
    }
}