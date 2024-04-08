/**
 * @note 数组的下标范围远远大于实际使用到的数组元素，此时使用离散化数组。
 * 	鉴于建立离散化数组本身就需要去重，查询时需要二分查找找到数组的索引，因此使用map代替也是等价的。map本身就具有去重和二分查询的性质。
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;

int quest[2][N];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	//输入
	cin >> n >> q;
	map<int, ll> mp;
	//“单点加”操作
	for (int i = 0; i < n; i++) {
		int num, val;
		cin >> num >> val;
		mp[num] = mp[num] + val;
	}
	//输入查询，添加点；
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		quest[0][i] = l;
		quest[1][i] = r;
		mp[l] = mp[l] + 0;
		mp[r] = mp[r] + 0;
	}

	//整理
	map<int, ll>::iterator it = mp.begin();
	ll sum = (*it).second;
	it++;
	for (; it != mp.end(); it++) {
		sum += (*it).second;
		(*it).second = sum;
	}

	for (int i = 0; i < q; i++) {
		ll l, r;
		ll res;
		l = quest[0][i];
		r = quest[1][i];
		int idxl, idxr;
		if (l == (*mp.begin()).first) {
			res = mp[r];
		} else {
			map<int, ll>::iterator it = mp.find(l);
			it--;

			res = mp[r] - (*it).second;
		}
		// cout << idxl << ' ' << idxr << ":: ";
		cout << res << '\n';
	}

	return 0;
}
