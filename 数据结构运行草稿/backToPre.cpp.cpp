#include <bits/stdc++.h>

using namespace std;
int priority(char ch)
{
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return -1;
}

string transfer(string s)
{
    //运算数
    string res = "";
    //运算符栈
    stack<char> st;

    //对s的每个字符进行操作
    for(int i = 0; i < s.size(); i++)
    {
        //运算数直接进入答案
        if(s[i] <= '9' && s[i] >= '0')
        {
            res += s[i];
        }

        //左括号直接入栈
        if(s[i] == '(')
        {
            st.push(s[i]);
        }

        //碰见右括号弹栈直到左括号
        if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            //弹出左括号
            st.pop();
        }

        //运算符入栈前还要进行判断
        if(s[i] == '+' || s[i] == '-' ||
                s[i] == '*' || s[i] == '/')
        {
            //当前运算符优先级小于等于栈顶优先级弹栈直到优先级大
            while(!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                res += st.top();
                st.pop();
            }
            //s[i]压栈
            st.push(s[i]);
        }
    }
    //将剩余的符号全都弹栈
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}
int main()
{
    string s;
    getline(cin, s);
    string res = transfer(s);
    cout << res;
}
