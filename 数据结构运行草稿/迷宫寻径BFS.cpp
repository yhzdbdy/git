#include<bits/stdc++.h>
using namespace std;
//BFS使用队列来操作
//全局常量 
const int MAXN = 1001;
//地图 
char MAP[MAXN][MAXN];
//和地图一样的大小，标记这个位置是否已经走过 
int ifVisit[MAXN][MAXN] = {{0}};
//标记这个位置到起点的最短距离
int digitDistance[MAXN][MAXN] = {{0}};
//标记上下左右的坐标变化情况
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0}; 
//点类
class Point {
public:
	int x;
	int y;
	Point(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
}; 

bool fisible(int x, int y, int R, int C) {
	if(x >= 0 && x < C && y >= 0 && y < R && ifVisit[x][y] == 0 && MAP[x][y] == '.')
		return true;
	return false;
}

int BFS(int R, int C) {
	//队列,用来广度搜索点 
	queue<Point> que;
	//初始化起点 
	Point point(0, 0);
	que.push(point);
	ifVisit[0][0] = 1; digitDistance[0][0] = 1;
	
	while(!que.empty()) {
		//出队 
		Point p = que.front();
		que.pop();
		//分别上下左右找到下一个点、
		for(int i = 0; i < 4; i++) {
			//找到这个点的坐标 
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if(fisible(nx, ny, R, C)) {
				//距离加一 
				digitDistance[nx][ny] = digitDistance[p.x][p.y] + 1;
				//标记这个点被访问过了
				ifVisit[nx][ny] = 1;
				//到达终点就返回
				if(nx == C - 1 && ny == R - 1) return  digitDistance[nx][ny];
				//否则继续入队
				Point po(nx, ny);
				que.push(po); 
			} 
		} 
	}
	//找不到终点
	return -1; 
}
int main() {
	int R, C;//长宽 
	cin >> R >> C;
	//剪枝
	if(R == 1 && C == 1) {
		cout << 1;
		return 0;
	}
	//读取地图情况 
	for(int i = 0; i < R; i ++) {
		for(int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}
	cout << BFS(R, C);
	return 0;
} 

