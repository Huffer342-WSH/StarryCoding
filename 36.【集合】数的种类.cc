/**
 * @note n<5000,a<100,所以所有组合的总数不会超过500000个
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
int a[N];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bitset<500001> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	s[0] = true;
	for (int i = 0; i < n; i++) {
		s |= s << a[i];
	}
	cout << s.count();

	return 0;
}
