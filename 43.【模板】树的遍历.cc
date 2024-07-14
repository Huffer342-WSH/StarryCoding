#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 60;
int n;

//子节点到父节点的映射
int s2p[N];

//父节点到子节点的映射，每个父节点对应一个vector<int>，其中保存其所有子节点
vector<int> p2s[N];

void dfs(int x)
{
	cout << x << ' ';
	for (int i : p2s[x]) {
		dfs(i);
	}
}
void bfs(int x)
{
	queue<int> nodes;
	nodes.push(x);
	while (!nodes.empty()) {
		int p;
		p = nodes.front();
		nodes.pop();
		for (int i : p2s[p]) {
			nodes.push(i);
		}
		cout << p << ' ';
	}
	cout << endl;
}
void solve()
{
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int s, p;
		s = i;
		cin >> p;
		s2p[i] = p;
		p2s[p].push_back(s);
	}

	dfs(1);
	cout << endl;
	bfs(1);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
