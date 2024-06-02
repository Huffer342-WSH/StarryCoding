#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

ll c[N];
ll a[N];
int n;

static inline int lowbit(int x)
{
	return x & (-x);
}

void buildTree()
{
	for (size_t i = 1; i <= n; i++) {
		c[i] += a[i];
		int j = i + lowbit(i);
		if (j <= n)
			c[j] += c[i];
	}
}

void printC()
{
	// for (size_t i = 1; i <= n; i++) {
	// 	printf("%d ", c[i]);
	// }
	// printf("\n\n");
}
void add(int k, int v)
{
	while (k <= n) {
		c[k] += v;
		k += lowbit(k);
	}
	printC();
}

ll getSum(int k)
{
	ll sum = 0;
	while (k) {
		sum += c[k];
		k -= lowbit(k);
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
	buildTree();

	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int k, v;
			cin >> k >> v;
			add(k, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << getSum(r) - getSum(l - 1) << endl;
		}
	}

	return 0;
}
