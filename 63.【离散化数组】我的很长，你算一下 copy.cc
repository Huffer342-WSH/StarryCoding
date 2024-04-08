/**
 * @note 数组的下标范围远远大于实际使用到的数组元素，此时使用离散化数组
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;

struct Data_t {
	int num;
	int val;
	bool operator<(const Data_t &u) const
	{
		return num < u.num;
	}
};

int quest[2][N];
int num[N];
ll pre[N];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	//输入
	cin >> n >> q;
	vector<Data_t> a;
	for (int i = 0; i < n; i++) {
		Data_t x;
		cin >> x.num >> x.val;
		a.push_back(x);
	}
	for (int i = 0; i < q; i++) {
		Data_t x;
		cin >> quest[0][i] >> quest[1][i];
		x.num = quest[0][i];
		x.val = 0;
		a.push_back(x);
		x.num = quest[1][i];
		a.push_back(x);
	}

	//整理
	sort(a.begin(), a.end());
	int l, r;
	for (l = 0, r = 1; r < a.size(); r++) {
		if (a[r].num == a[l].num) {
			a[l].val += a[r].val;
		} else {
			l++;
			a[l] = a[r];
		}
	}
	ll sum = 0;
	pre[0] = 0;
	for (int i = 0; i <= l; i++) {
		sum += a[i].val;
		num[i + 1] = a[i].num;
		pre[i + 1] = sum;
	}

	//查询
	int length = l + 1;
	// for (int i = 0; i <= length; i++) {
	// 	cout << i << ' ' << num[i] << '\t' << pre[i] << '\n';
	// }
	// cout << "res\n";

	for (int i = 0; i < q; i++) {
		ll l, r;
		ll res;
		l = quest[0][i];
		r = quest[1][i];
		int idxl, idxr;
		idxl = lower_bound(num + 1, num + length + 1, l) - num;
		idxr = lower_bound(num + 1, num + length + 1, r) - num;
		res = pre[idxr] - pre[idxl - 1];
		// cout << idxl << ' ' << idxr << ":: ";
		cout << res << '\n';
	}

	return 0;
}
