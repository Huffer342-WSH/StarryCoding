#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

vector<int> g[N];
vector<int> res;
bitset<N> bs;

int n, m;

void dfs(int x)
{
	if (bs[x] == true) {
		return;
	}
	bs.set(x);
	res.push_back(x);
	for (int i : g[x]) {
		dfs(i);
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int src, dest;
		cin >> src >> dest;
		g[src].push_back(dest);
	}
	dfs(1);
	sort(res.begin(), res.end());
	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
