// KMP在20260921首次攻破
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    //next数组是针对匹配串来构建的
    void buildNext(string& needle, vector<int>& next) {
        
        //k代表每次最长相等前缀的下一个位置，这个位置的字符和ne[j]进行判断相等
        int k = -1;
        next[0] = -1;

        //创建next数组的第j+1个元素，j+1 < size
        for(int j = 0; j < needle.size() - 1; j++) {
            k = next[j];

            //不断缩小判断相等的长度
            while(k >= 0 && needle[j] != needle[k]) {
                k = next[k];
            }
            //走出来了代表ne[j] = ne[k],直接等于这个位置的相等前缀长度加一
            next[j+1] = ++k;
        }
//        for(int i = 0; i < next.size(); i++) {
//        	cout << next[i] << endl;
//		}
    }
public:
    // KMP函数
    int strStr(string haystack, string needle) {
        //创建next数组
        vector<int> next(needle.size());
        buildNext(needle, next);
        // 两个字符串开始匹配的下标
        int i = 0; // 主串
        int j = 0; // 从串

        // 匹配过程，一定要背下来
        while (i < haystack.size() && j < needle.size()) {
            // 在这里同时移动i和j分为两种情况
            if (j == -1 || haystack[i] == needle[j]) {
                /*
                第一是 j = -1,
                这代表从串的第一个就不匹配，此时我们直接把从串往后移动一位
                第二是正常匹配，此时我们也需要两个指针一起移动匹配下一个位置
                */
                i++;
                j++;
            } else {
                //在这个位置不匹配了，我们直接移动从串到next数组对应的位置，主串的i指针不需要移动
                j = next[j];
            }
        }

        return (j == needle.size()) ? i - j : -1;
    }

};
    int main() {
    	string s;
    	getline(cin, s);
    	string p;
    	getline(cin, p);
    	Solution slo;
    	cout << slo.strStr(s, p);
    	return 0;
	}