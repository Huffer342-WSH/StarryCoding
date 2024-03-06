#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
ll diff[N][N];
ll a[N][N];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	// 得到差分矩阵
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll t = a[i][j];
			diff[i][j] += t;
			diff[i + 1][j + 1] += t;
			diff[i + 1][j] -= t;
			diff[i][j + 1] -= t;
		}
	}

	for (int i = 0; i < q; i++) {
		int x1, x2, y1, y2, v;
		cin >> x1 >> y1 >> x2 >> y2 >> v;
		x2++;
		y2++;
		diff[x1][y1] += v;
		diff[x2][y2] += v;
		diff[x2][y1] -= v;
		diff[x1][y2] -= v;
	}

	/*复原矩阵*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + diff[i][j];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
