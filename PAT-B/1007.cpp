/*1007 素数对猜想
Score 20
Author CHEN, Yue
Organization 浙江大学

让我们定义dn​为：dn​=pn+1​−pn​，其中pi​是第i个素数。显然有d1​=1，且对于n>1有dn​是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<105)，请计算不超过N的满足猜想的素数对的个数。
输入格式:

输入在一行给出正整数N。
输出格式:

在一行中输出不超过N的满足猜想的素数对的个数。
输入样例:

20

输出样例:

4

Code Size Limit
16 KB
Time Limit
200 ms
Memory Limit
64 MB
Stack size limit
8192 KB*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit;
    cin >> limit;
    int numOfPairs = 0;
    for (int i = 2; i <= limit - 2; i++) {
        if (isPrime(i) && isPrime(i + 1)) {
            continue;
        } else if (isPrime(i) && isPrime(i + 2)) {
            numOfPairs++;
        }
    }
    cout << numOfPairs << endl;
}
