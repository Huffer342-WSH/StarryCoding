#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 2e5 + 5;

ll a[N];
ll treeD[N]; //使用后原数组的差分数组构建的树状数组
ll treeID[N];
ll n;

static inline ll lowbit(ll x)
{
	return x & (-x);
}

void add(ll k, ll v)
{
	for (int i = k; i <= n; i += lowbit(i)) {
		treeD[i] += v;
		treeID[i] += (ll)k * v;
	}
}

ll getSum(ll k)
{
	ll sum = 0;
	for (ll i = k; i > 0; i -= lowbit(i)) {
		sum += (k + 1) * treeD[i] - treeID[i];
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> n >> q;
	for (size_t i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (size_t i = 1; i <= n; i++) {
		add(i, a[i]);
		add(i + 1, -a[i]);
	}

	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			add(l, v);
			add(r + 1, -v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << getSum(r) - getSum(l - 1) << endl;
		}
	}

	return 0;
}
