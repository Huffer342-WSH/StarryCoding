#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int n;
int a[N];
bitset<N> st;

void dfs(int x)
{
	// cout << x << ' ';
	if (x > n) {
		for (int i = 1; i <= n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	} else {
		for (int i = 1; i <= n; i++) {
			if (st[i] == false) {
				st[i] = true;
				a[x] = i;
				dfs(x + 1);
				st[i] = false;
			}
		}
	}
	return;
}
void solve()
{
	cin >> n;

	dfs(1);
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
