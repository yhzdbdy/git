#include<bits/stdc++.h>
using namespace std;

//全局变量
int n;
string s;
//一个看起来就是回溯DFS来处理的题目，想想那个回溯的树
void DFS(int index) {
    //终止条件
    if(index == n) {
        cout << s << endl;
        return;
    }
    //横向，每次只有两个选择，一个是填N，一个是填Y

    s[index] = 'N';
    //用加一来隐藏回溯的实现
    DFS(index + 1);

    s[index] = 'Y';
    DFS(index + 1);
}
int main() {
    cin >> n;
    s.resize(n);
    DFS(0);
    return 0;
}