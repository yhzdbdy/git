/*代码随想录 岛屿问题七 创建最大岛屿*/
/*首先拿到一道难题需要构建思路*/
/*我们首先使用DFS把每个孤岛全都遍历出来*
/*接下来我们遍历整个图，在碰到0时构建一个岛屿，和之前的孤岛合并，观察最大岛屿面积*/

#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

/*
现在还有一个问题就是，如果整个图都是1，那么我们就没有机会去增加岛屿了
所以我们如果DFS发现全都是1，直接返回n*m
*/



//用来标记某一块孤岛 <孤岛标号， 孤岛面积>
unordered_map<int, int> Mymap;
//孤岛下标从2开始
int mark = 2;

//在增加岛屿部分，我们遍历这个点的四个方向可能得到的是一整块相同的孤岛
//所以需要一个set集合来标记当前孤岛已经添加过了
//<mark孤岛标号>
unordered_set<int> Myset; 

//标记全都不是陆地
bool isAllLand = true;

void DFS(vector<vector<int>>& grid ,vector<vector<bool>>& visited, int x, int y) {
    //四个方向
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

        //不能写在这里
        // if(grid[xx][yy] == 0) {
        //     isAllLand = false;
        // }

        if(grid[xx][yy] == 1 && !visited[xx][yy]) {

            grid[xx][yy] = mark;
            Mymap[mark]++;
            //标记访问过
            visited[xx][yy] = true;
            DFS(grid, visited, xx, yy);
        }
    }

}

int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    //开始遍历整个图，寻找孤岛
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //由于下面只有1才会进入DFS，所以我们在这里判断是否全是陆地
            if(grid[i][j] == 0) {
                isAllLand = false;
            }
            //碰到全新的陆地就开始DFS
            if(!visited[i][j] && grid[i][j] == 1) {
                //一定要记住先处理第一个点，我们的DFS里面对进入的点不会进行操作
                grid[i][j] = mark;
                Mymap[mark]++;
                visited[i][j] = true;
                DFS(grid, visited, i, j);
                //走出这个入口代表当前孤岛结束遍历了
                mark++;//孤岛标号加一，下一个孤岛
            }
        }
    }

    //全是陆地直接返回m*n
    if(isAllLand) {
        cout << n*m << endl;
        return 0;
    }

    //现在开始添加岛屿部分
    int result = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //碰到海水0
            if(grid[i][j] == 0) {
                //需要重置set  ！！！！不要忘记了
                Myset.clear();

                count = 1;//标记当前增加以后的面积，初始化为点，面积为1

                //寻找这个点的四个方向的孤岛
                for(int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    //越界
                    if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                    //判断（xx， yy）是哪个岛屿或者海水
                    /*当前这个方向的孤岛已经添加过了*/
                    if(Myset.find(grid[xx][yy]) != Myset.end()) continue;
                    //否则添加面积,这里如果是海水加的就是0，无所谓的
                    count += Mymap[grid[xx][yy]];
                    //标记当前孤岛已经添加过了
                    Myset.insert(grid[xx][yy]);
                }
            }
            result = max(result, count);
        }
    }

    cout << result << endl;
}