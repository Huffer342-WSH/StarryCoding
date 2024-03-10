#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct elm {
	int h, s, w;
	bool operator<(const elm &u) const
	{
		if (h == u.h && s == u.s)
			return w > u.w;
		if (h == u.h)
			return s > u.s;
		return h > u.h;
	}
};
elm a[N];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].h >> a[i].s >> a[i].w;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i].h << ' ' << a[i].s << ' ' << a[i].w << '\n';
	}
	return 0;
}
