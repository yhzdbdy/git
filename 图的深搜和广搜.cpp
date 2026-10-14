#include<bits/stdc++.h>
using namespace std;
/* 我们使用邻接表来存储图 */

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

//初始化顶点
void initVertex(Vertex vertex[], int n) {
    for(int i = 0; i < n; i++) {
        //顶点下标依次增大
        vertex[i].verName = i;
        //顶点的边初始化为空
        vertex[i].adjacent = nullptr;
    }
}

//初始化顶点的每条边
void addEdge(Vertex vertex[], int from, int to, int cost) {
    //初始化一条边
    Edge* adjacent = new Edge(to, cost, nullptr);

    //找到from的这个顶点
    if(vertex[from].adjacent == nullptr) {
        //如果他的边是空的，直接变成第一个边
        vertex[from].adjacent = adjacent;
    }

    //如果非空，即这个顶点已经有边了
    Edge* q = vertex[from].adjacent;
    //遍历顶点的边找到最后一个边
    while(q -> next != nullptr) {
        q = q -> next;
    }
    //让他变成最后一条边
    q -> next = adjacent;
}

class DFS{
private:
    //回溯才需要用到这个容器
    vector<vector<int>> ans;
public:
    //我们这里考虑反向边，要用一个visited数组标记是否已经遍历了这个节点
    void dfs(Vertex* head, vector<int> path, int visited[],int vetex, int n) {
        //终止条件
        if(path.size() == n) {
            return;
        }

        path.push_back(vetex);
        //标记访问过当前顶点
        visited[vetex] = 1;

        //访问顶点的所有边
        for(Edge* cur = head -> adjacent; cur != nullptr; cur = cur->next) {
            //如果没有访问过就访问
            if(visited[cur -> verAdj] == 0) {
                //递归
                dfs(head, path, visited, cur -> verAdj, n);
                //这里只要一次遍历所有元素，不需要回溯
            }
        }
    }

    //用栈来模拟回溯
    void dfsWithStack(Vertex* head, int vertex, int visited[]) {
        stack<int> st;
        //先压入第一个顶点
        st.push(vertex);

        //栈非空时遍历
        while(!st.empty()) {
            int v = st.top();
            st.pop();
            //没访问过才打印
            if(visited[v] == 0) {
                //访问当前节点
                cout << v << endl;
                visited[v] = 1;
                for(Edge* cur = head[v].adjacent; cur != nullptr; cur = cur -> next) {
                    //没有访问过才入栈
                    if(visited[cur -> verAdj] == 0) {
                        st.push(cur -> verAdj);
                    }
                }
            }
        }
    }
};