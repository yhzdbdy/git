#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0 ,0};
void DFS(vector<vector<int>>& gragh, vector<vector<bool>>& visited, int x, int y, int &count) {
    int row = gragh.size();
    int col = gragh[0].size();

    //四个方向
    for(int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue;
        //陆地并且么有访问过
        if(gragh[nextX][nextY] == 1 && !visited[nextX][nextY]) {
            //我们在调用递归之前就声明访问过，所以不要忘了起点
            visited[nextX][nextY] = true;
            //岛屿大小加一
            count++;
            DFS(gragh, visited, nextX, nextY, count);
        }
    }
} 
int getMaxAre(vector<vector<int>>& gragh, vector<vector<bool>>& visited) {
    int row = gragh.size();
    int col = gragh[0].size();

    int result = 0;
    //找到每一片岛屿并且计算面积
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            //当前碰到陆地并且还没有访问过
            if(gragh[i][j] == 1 && !visited[i][j]) {
                //先初始化为1
                int count = 1;
                //起点需要标记为访问过  ！！！！一定要记住，在这里错过
                visited[i][j] = true;
                DFS(gragh, visited, i, j, count);
                result = max(result, count);
            }
        }
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gragh(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> gragh[i][j];
        }
    }
    cout << getMaxAre(gragh, visited);
}