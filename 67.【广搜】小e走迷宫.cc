/**
 * 用bfs，不要用dfs
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

int n, m;
char maze[N][N];
int dis[N][N];

struct Pos_t {
	int x, y, d;
};

bool isInMaze(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '0';
}

void dfs(int x, int y, int dep)
{
	if (isInMaze(x, y) && (dis[x][y] == -1 || dis[x][y] > dep)) {
		dis[x][y] = dep;
		// cout << x << ' ' << y << ' ' << dep << '\n';

		//递归
		dfs(x - 1, y, dep + 1);
		dfs(x + 1, y, dep + 1);
		dfs(x, y - 1, dep + 1);
		dfs(x, y + 1, dep + 1);
	} else {
		return;
	}
}

void bfs(int x, int y, int dep)
{
	queue<Pos_t> que;

	que.push({ x, y });

	while (!que.empty()) {
		Pos_t t = que.front();
		que.pop();

		if (isInMaze(t.x, t.y) && (dis[t.x][t.y] == -1 || dis[t.x][t.y] > t.d)) {
			dis[t.x][t.y] = t.d;
			que.push({ t.x - 1, t.y, t.d + 1 });
			que.push({ t.x + 1, t.y, t.d + 1 });
			que.push({ t.x, t.y - 1, t.d + 1 });
			que.push({ t.x, t.y + 1, t.d + 1 });
		}
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			dis[i][j] = -1;
		}
	}
	bfs(0, 0, 0);
	cout << dis[n - 1][m - 1] << '\n';
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
