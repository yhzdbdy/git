/*代码随想录 岛屿问题六 高山流水*/
/*题目就是要给出从这个点出发可以已知往下走到两个边界的那些点*/
/*正常的想法是我们遍历寻找点，观察它是不是可以按照要求到达两个边界*/
/*但是我们参考前面的寻找孤岛，可以从边界出发，将可以到达的点标记，有两个标记的点就是目标*/

#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0 ,-1, 1};
int dy[4] = {-1, 1, 0, 0};

//深搜用来标记点
void DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int row = grid.size();
    int col = grid[0].size();

    //四个方向
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= row || yy < 0 || yy >= col) continue;
        if(!visited[xx][yy] && grid[xx][yy] >= grid[x][y]) {
            visited[xx][yy] = true;
            DFS(grid, visited, xx, yy);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> firstMark(n, vector<bool>(m, false));
    vector<vector<bool>> secondMark(n, vector<bool>(m, false));

    //最上和最下
    for(int i = 0; i < n; i++) {
        //在这里我们有一个处理的细节就是我们没有把初始边界上面的点标记true，所以进入递归之前先标记一下
        firstMark[i][0] = true;
        secondMark[i][m - 1] = true;
        DFS(grid, firstMark, i, 0);
        DFS(grid, secondMark, i, m - 1);
    }
    for(int j = 0; j < m; j++) {
        firstMark[0][j] = true;
        secondMark[n - 1][j] = true;
        DFS(grid, firstMark, 0, j);
        DFS(grid, secondMark, n - 1, j);
    }

    //遍历整个图，寻找两个标记都有的点
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(firstMark[i][j] && secondMark[i][j]) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}