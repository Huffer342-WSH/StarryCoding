#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			ans ^= x;
		}
		cout << ans << '\n';
	}
	return 0;
}
