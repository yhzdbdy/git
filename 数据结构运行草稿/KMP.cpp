#include<bits/stdc++.h>
using namespace std;
vector<int> buildNext(string& p, vector<int>& next) {
	//核心思想是如果p[i] = p[k]，next【i+1】= next[i] 
	
	//标记下一次判断的位置
	int k = -1;
	//第一个元素是-1
	next[0] = -1;
	
	for(int i = 0; i < p.size() - 1; i++) {
		k = next[i];
		//判断在相同前缀情况下下一个位置是否也匹配
		while(k >= 0 && p[i] != p[k]) {
			//不匹配就更新区间，取一个更小的区间
			k = next[k];
		}
		//走到这里证明匹配了
		next[i+1] = ++k;
	}
	return next;
}
int KMP(string& p, string& t) {
	int n = p.size();
	int m = t.size();
	//匹配两个字符串的下标
	int i = 0; int j = 0;
	
	//创建next数组
	vector<int> next(t.size());
	buildNext(t, next);
	//开始匹配
	while(i < n && j < m) {
		if(j == -1 || p[i] == t[j]) {
			j++;
			i++;
		}else {
			j = next[j];
		}
	}
	return (j == m) ? i - m : -1;
}
int main() {
	//目标字符串
	string p;
	getline(cin, p);
	//匹配字符串
	string t;
	getline(cin, t);
	int index = KMP(p, t);
	cout << index;
}
