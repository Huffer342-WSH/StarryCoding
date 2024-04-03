#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int p = 1e9 + 7;
const LL N = 2e5 + 9;
LL n, m, k, q;
LL a[N], sum[N];
void solve()
{
	int a, b;
	int res;
	cin >> a >> b;
	if (sum[a - 1] == b)
		res = a;
	else if (sum[a] == b)
		res = a + 2;
	else
		res = a + 1;
	cout << res << '\n';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	for (int i = 1; i < N; i++)
		sum[i] = sum[i - 1] ^ i;
	while (T--) {
		solve();
	}
	return 0;
}
