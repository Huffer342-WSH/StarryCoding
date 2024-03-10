#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int a[N];
void solve()
{
	int n;
	cin >> n;
	vector<int> map(N, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 0;
	int res = 0;
	map[a[0]] = 0;
	for (r = 1; r < n; r++) {
		int x = a[r];
		if (map[x] >= l) {
			l = map[x] + 1;
		}
		map[x] = r;
		res = max(r - l + 1, res);
	}
	cout << res << '\n';
	return;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}

	return 0;
}
