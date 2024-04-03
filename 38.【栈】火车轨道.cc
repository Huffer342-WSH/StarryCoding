#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	queue<int> q;
	stack<int> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.emplace(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!s.empty() && s.top() == i) {
			//查看栈顶
			s.pop();
		} else {
			//查看队列中的元素，不符合的入栈
			while (!q.empty()) {
				if (q.front() == i) {
					//符合，出队列
					q.pop();
					goto NEXT;
				} else {
					//不符合，队列头入栈
					s.push(q.front());
					q.pop();
				}
			}
			if (q.empty()) {
				cout << "No";
				return 0;
			}
		}

NEXT:
		continue;
	}
	cout << "Yes";

	return 0;
}
