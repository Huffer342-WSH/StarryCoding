#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int a[N], amax[N], amin[N];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	queue<int> que;
	multiset<int> ms;
	cin >> n >> k;

	for (int i = 0; i < k - 1; i++) {
		int x;
		cin >> x;
		que.push(x);
		ms.insert(x);
	}

	for (int i = 0; i < n - k + 1; i++) {
		int x;
		cin >> x;
		que.push(x);
		ms.insert(x);
		amax[i] = *(--ms.end());
		amin[i] = *(ms.begin());
		ms.erase(ms.find(que.front()));
		que.pop();
	}

	for (int i = 0; i < n - k + 1; i++) {
		cout << amax[i] << ' ';
	}
	cout << '\n';

	for (int i = 0; i < n - k + 1; i++) {
		cout << amin[i] << ' ';
	}
	return 0;
}
