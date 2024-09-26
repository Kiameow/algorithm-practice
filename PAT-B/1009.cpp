/*
1009 说反话
Score 20
Author CHEN, Yue
Organization 浙江大学

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
输入格式：

测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。
输出格式：

每个测试用例的输出占一行，输出倒序后的句子。
输入样例：

Hello World Here I Come

输出样例：

Come I Here World Hello

鸣谢用户 无影 修正数据！
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
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> split(std::string s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, s.find(delimiter) + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> tokens = split(s, " ");
    reverse(tokens.begin(), tokens.end());
    bool first = true;
    for (auto token : tokens) {
        if (!first) {
            cout << " ";
        } else {
            first = false;
        }
        cout << token;
    }
    cout << endl;
}