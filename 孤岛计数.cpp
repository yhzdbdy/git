#include<bits/stdc++.h>
using namespace std;
//上下左右
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


//我们的逻辑是如果这个点是陆地并且未访问过，就从这个点开始深搜
void DFS(vector<vector<int>>& graph, int x, int y, vector<vector<bool>>& visited) {
    //这个函数要实现的功能就是给一整块陆地标记已经访问过
    int row = graph.size();
    int col = graph[0].size();

    //直接四个方向
    for(int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        //越界直接跳过
        if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue;
        //下面这个点是在图里面的
        if(graph[nextX][nextY] == 1 && visited[nextX][nextY] == false) {
            //是陆地并且没有访问过
            visited[nextX][nextY] = true;//标记访问过
            DFS(graph, nextX, nextY, visited);
        }
    }
}
/*注意我们没有设置终止条件，我们递归的入口是有条件的，如果碰到0就会退出*/

//

int countIsland(vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    int count = 0;
    int row = graph.size();
    int col = graph[0].size();
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            //碰到当前还没有访问过的陆地
            if(!visited[i][j] && graph[i][j] == 1) {
                //标记已访问
                visited[i][j] = true;
                count++;
                DFS(graph,i,j,visited);
            }
        }
    }

    return count;
}


int main() {
    int m, n;
    //n行m列
    cin >> n >> m;
    //初始化图
    vector<vector<int>> graph(n, vector<int>(m, 0));
    //初始化一个visited数组标记是否已经访问过这个陆地
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    cout << countIsland(graph, visited);
}