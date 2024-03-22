#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	priority_queue<int, vector<int> > q;
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x;
		if (x == 1) {
			cin >> y;
			q.push(y);
		} else {
			if (!q.empty())
				q.pop();
		}
	}
	long long sum = 0;
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}
	cout << sum;

	return 0;
}
