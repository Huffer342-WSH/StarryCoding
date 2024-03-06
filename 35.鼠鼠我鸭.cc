#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int flag[N];
ll s[N];
ll a[N];
void solve()
{
	ll sum1 = 0, sum0 = 0, max = 0;
	int n;
	cin >> n;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> flag[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (flag[i])
			sum1 += a[i];
		if (!flag[i]) {
			sum0 += a[i];
			if (sum0 > max) {
				max = sum0;
			}
		} else {
			sum0 -= a[i];
			if (sum0 < 0)
				sum0 = 0;
		}
	}

	sum1 += max;
	cout << sum1 << '\n';
	return;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
