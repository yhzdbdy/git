/*代码随想录  岛屿问题四*/
/*
我们需要寻找不和边界接触的岛屿
直接从边界开始遍历，把和边界相连的岛屿全都变成0
最后遍历整个图，累加为1的点
*/

#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0 ,0};

//入队的基本要求，在入队之前就遍历这个point
void BFS(vector<vector<int>>& gragh, int x, int y) {
    int row = gragh.size();
    int col = gragh[0].size();

    queue<pair<int, int>> que;
    //起点入队
    que.push({x, y});
    gragh[x][y] = 0;
    while(!que.empty()) {
        auto point = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = point.first + dx[i];
            int nextY = point.second + dy[i];
            if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue;
            if(gragh[nextX][nextY] == 1) {
                gragh[nextX][nextY] = 0;
                que.push({nextX, nextY});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gragh(n, vector<int>(m, 0));
    //这次不需要visited数组，我们直接把那些岛屿变成0了

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> gragh[i][j];
        }
    }

    //左右
    for(int i = 0; i < n; i++) {
        if(gragh[i][0] == 1) BFS(gragh, i, 0);
        if(gragh[i][m - 1] == 1) BFS(gragh, i, m-1);
    }
    //上下
    for(int j = 0; j < m; j++) {
        if(gragh[0][j] == 1) BFS(gragh, 0, j);
        if(gragh[n - 1][j] == 1) BFS(gragh, n-1, j);
    }

    int res = 0;
    //遍历寻找所有为1得点
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(gragh[i][j] == 1) res++;
        }
    }
    cout << res;
}