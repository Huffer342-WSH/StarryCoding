#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
int a[N];
int t[N]; //权值数组的树状数组
vector<int> X; // 排序去重a[i],作为原数组和离散数组的映射

int lowbit(int x)
{
	return x & -x;
}

void update(int k, int v)
{
	for (int i = k; i <= X.size(); i += lowbit(i)) {
		t[i] += v;
	}
}

int getsum(int k)
{
	int res = 0;
	for (int i = k; i > 0; i -= lowbit(i)) {
		res += t[i];
	}
	return res;
}

int mapNum2Index(int n)
{
	return lower_bound(X.begin(), X.end(), n) - X.begin() + 1;
}

void solve()
{
	ll res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		X.push_back(a[i]);
	}

	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()));

	for (int i = 0; i < n; i++) {
		res += getsum(X.size()) - getsum(mapNum2Index(a[i])); //总数-小于等于a[i]的数的数量
		update(mapNum2Index(a[i]), 1); //把a[i]添加到树状数组中
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
