#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int a[N];

void solve1(int a[], int n, int k)
{
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && dq.front() <= i - k)
			dq.pop_front();
		while (!dq.empty() && a[dq.back()] >= a[i])
			dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1)
			cout << a[dq.front()] << ' ';
	}
}
void solve2(int a[], int n, int k)
{
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && dq.front() <= i - k)
			dq.pop_front();
		while (!dq.empty() && a[dq.back()] <= a[i])
			dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1)
			cout << a[dq.front()] << ' ';
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	queue<int> que;
	multiset<int> ms;
	cin >> n >> k;
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve2(a, n, k);
	cout << endl;
	solve1(a, n, k);

	return 0;
}
