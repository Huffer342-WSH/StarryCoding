#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
void solve()
{
	int n;
	int cnt;
	map<string, int> m;
	vector<string> vec;
	cin >> n;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m[s] == 0) {
			vec.emplace_back(s);
			cnt++;
		}
		m[s] = m[s] + 1;
	}

	for (auto &i : vec) {
		cout << i << ' ' << m[i] << '\n';
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}
	return 0;
}
