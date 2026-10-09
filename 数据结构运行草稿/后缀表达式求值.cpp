#include<bits/stdc++.h>
using namespace std;
int caculate(int a, int b, char c) {
	if(c == '+') return a + b;
	if(c == '-') return b - a;
	if(c == '*') return a * b;
	return b / a;
}
int getValue(string& s) {
	//运算数栈
	stack<int> ans;

	for(int i = 0; i < s.size(); i++) {
		//操作数直接入栈，注意我们可能需要一个10之类的连续数 
		if(s[i] <= '9' && s[i] >= '0') {
			int tmp = 0;
			while(s[i] <= '9' && s[i] >= '0') {
				tmp *= 10;
				tmp += s[i] - '0';
				i++;
			}
			ans.push(tmp);
		} else if(s[i] == '+' || s[i] == '-' ||
		          s[i] == '*' || s[i] == '/') {
			//直接拿出两个元素进行运算
			int a = ans.top();
			ans.pop();
			int b = ans.top();
			ans.pop();
			int p = caculate(a, b, s[i]);
			ans.push(p);
		}
	}
	return ans.top();
}
int main() {
	string s;
	getline(cin, s);
	cout << getValue(s);
	return 0;
}

