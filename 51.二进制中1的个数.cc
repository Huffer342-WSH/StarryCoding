#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

void solve()
{
	unsigned int x;
	int res = 0;
	cin >> x;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	cout << res << ' ';
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}

	return 0;
}
