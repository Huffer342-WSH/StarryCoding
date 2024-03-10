#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

typedef struct {
	int h, s, w;
} elm;
elm a[N];

bool cmp(elm &a, elm &b)
{
	if (a.h == b.h && a.s == b.s)
		return a.w > b.w;
	if (a.h == b.h)
		return a.s > b.s;
	return a.h > b.h;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].h >> a[i].s >> a[i].w;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << a[i].h << ' ' << a[i].s << ' ' << a[i].w << '\n';
	}

	return 0;
}
