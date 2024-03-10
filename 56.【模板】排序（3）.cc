#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int c[N];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i = 0; i < N; i++) {
		while (c[i]--) {
			cout << i << ' ';
		}
	}

	return 0;
}
