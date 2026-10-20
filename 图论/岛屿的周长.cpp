/*代码随想录  岛屿问题七 岛屿的周长*/
/*这题很简单，从为1的点向四个方向遍历，碰到0周长就加一*/
/*1在图的边界周长也加一就行*/

#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                //四个方向
                for(int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    //如果碰到水域或者越界了就加一
                    if(grid[xx][yy] == 0 || xx < 0 || xx >= n || yy < 0 || yy >= m) 
                        result++;
                }
            }
        }
    }
    cout << result << endl;
}