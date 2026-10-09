#include<bits/stdc++.h>
using namespace std;
//全局变量
const int MAXN = 1001; 
int m, n;
//地图
char MAP[MAXN][MAXN];
//和地图一样大的一个哈希表，用来标记这个地方是否已经走过，初始化为0都没有走过
int ifVisit[MAXN][MAXN] = {{0}};
//数组用来标记走过的路径
int ans[MAXN * MAXN];
//上下左右
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

//位置没有越界，地图上面可以访问，还没有被访问过 
bool fisible(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m && MAP[x][y] != '#' && ifVisit[x][y] != 1) 
		return true;
	return false;
}

//标记现在的xy位置，目的地位置，路径数组，数组的下标 
bool findPath(int x, int y, int desX, int desY, int ans[], int k) {
	
	ifVisit[x][y] = 1;//标记这里已经来过了
	
	//递归终止条件,记住这里我们找到路了以后需要一路一直返回 
	if(x == desX && y == desY) return true;
	 
	//本轮判断,四个方向全都要判断 
	for(int i = 0; i < 4; i++) {
		//更新下一步位置 ，一定要牢记，不能直接修改x ，否则for循环操作的不是同一个位置了 
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(fisible(nx, ny)) {//确定当前位置是合法的 
			//记录当前的行走方向 
			ans[k] = i; 
			//回溯,下标加一即可  k+1 
			if(findPath(nx, ny, desX, desY, ans, k + 1)){
				//注意我们这里出触发find函数返回true的条件是什么，在递归终止条件那里 
				return true;
			}
		}
	}
	//四个方向全都不行，返回false 
	return false; 
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	//如果找到了合适的路径返回
	if(findPath(0, 0, n - 1, m - 1, ans, 0)) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
