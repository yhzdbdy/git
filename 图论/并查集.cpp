/*
并查集基础逻辑：
元素指向自己代表这个元素的根就是自己
father[i] = k 代表 i -> k 即代表这两个元素在同一个图里面有关系
*/

#include<bits/stdc++.h>
using namespace std;

class DSU{
private:
    int MAX = 1e5 + 10;
    vector<int> father;
public:
    //初始化：并查集的元素一开始指向的是自己
    DSU() : father(MAX, 0) {
        for(int i = 0; i < MAX; i++) {
            father[i] = i;
        }
    }

    //查找这个元素的根
    int find(int v) {
        //如果自己是自己的根就返回自己，如果不是就递归找到v的根返回
        return father[v] == v ? v : find(father[v]);
    }

    //判断两个元素是否同在一张联通图里面
    bool isSame(int m, int n) {
        //逻辑就是判断两个元素的根是不是同一个元素
        m = find(m);
        n = find(n);
        return m == n;
    }

    //添加两个元素的关系
    void join(int m, int n) {
        //先找到两个元素的根
        m = find(m);
        n = find(n);
        //已经有关系了直接返回不操作
        if(m == n) return;
        //直接让m的根为n
        father[m] = n;
    }
};