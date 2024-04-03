#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int arr[N];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	//输入
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//排序
	sort(arr, arr + n);

	for (int i = 0; i < q; i++) {
		int v;
		cin >> v;
		int l = 0, r = n;
		while (l + 1 != r) {
			int mid = (l + r) >> 1;
			if (arr[mid] < v) {
				l = mid;
			} else {
				r = mid;
			}
		}
		if (arr[r] == v)
			cout << r << " ";
		else
			cout << -1 << " ";
	}

	return 0;
}
