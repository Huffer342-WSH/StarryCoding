#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	stack<int> stk;
	for (size_t i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!stk.empty()) {
			if (stk.top() >= x) {
				stk.pop();
			} else {
				break;
			}
		}
		if (stk.empty()) {
			cout << -1 << ' ';
		} else {
			cout << stk.top() << ' ';
		}

		stk.push(x);
	}
	return 0;
}
