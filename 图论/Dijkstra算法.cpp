#include<bits/stdc++.h>
using namespace std;

/*
该算法的核心：
从没有遍历过的点里面寻找一个dist最小的点v，加入S集合
寻找v的分支节点w，如果从v到w的cost比原来的dist小，更新dist，pre = v
*/

//顶点类
class Edge;
class Vertex {
public:
    //顶点编号
    int verName;
    //这个顶点的边
    Edge* adjacent;
};
class Edge {
public:
    //边的终点
    int verAdj;
    //边的权值
    int cost;
    //顶点的下一条边
    Edge* next;
    Edge(int v, int c, Edge* edge) : verAdj(v), cost(c), next(edge) {}
};

int findMin(int S[], int dist[], int n) {
    int v = -1; int min = INT_MAX;
    //在！！！！！没有进入S集合的点！！！！！里面寻找最小的
    for(int j = 1; j <= n; j++) {
        if(S[j] == 0 && dist[j] < min) {
            v = j; min = dist[j];
        }
    }
    return v;
}

//我们引入两个数组，dist用来存储顶点到当前点的距离，pre标记当前点的前置节点
void Dijkstra(Vertex* head, int n, int u, int dist[], int pre[]) {
    int S[n + 1] = {0};
    //初始化dist全都是无穷大
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        pre[i] = -1;
    }
    //但是起点u到自己距离是0
    dist[u] = 0;

    //开始遍历整个图，注意图是从1到n
    for(int i = 1; i <= n; i++) {
        int v = findMin(S, dist, n);
        //找不到点代表不是连通图
        if(v == -1) return;
        //v入集合
        S[v] = 1;

        //遍历v的所有边更新dist
        for(Edge* e = head[v].adjacent; e != nullptr; e = e -> next) {
            //一定要记住是对于当前还没有入集合的点来说的
            if(S[e -> verAdj] == 0 && dist[v] + e->cost < dist[e -> verAdj]) {
                dist[e -> verAdj] = dist[v] + e -> cost;
                //标记当前点的前缀
                pre[e -> verAdj] = v;
            }
        }
    }
}