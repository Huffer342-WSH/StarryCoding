#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i : a) {
		cout << i << ' ';
	}

	return 0;
}
