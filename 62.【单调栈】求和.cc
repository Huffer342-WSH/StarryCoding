#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int v[N];
int num[N];
int top;
ll sum = 0;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	top = 0;
	for (int i = 0; i < _; i++) {
		int x;
		int cnt = 1;
		cin >> x;
		while (top != 0 && v[top - 1] >= x) {
			top--;
			cnt += num[top];
		}
		v[top] = x;
		num[top] = cnt;
		top++;
		for (int j = 0; j < top; j++) {
			sum += v[j] * num[j];
		}
	}
	cout << sum;
	return 0;
}
