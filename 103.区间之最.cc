#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;

int arr[N];
LL solve()
{
	LL res = 0;
	int arrLength, maxDiff;
	cin >> arrLength >> maxDiff;
	int left, right;
	for (int i = 0; i < arrLength; i++) {
		cin >> arr[i];
	}
	arr[arrLength] = 3e7;

	multiset<int> mySet;
	left = 0;
	int diff = 0;
	for (left = 0, right = 0; left < arrLength; left++) {
		while (right < arrLength) {
			mySet.insert(arr[right]);
			diff = *mySet.rbegin() - *mySet.begin();
			// cout << "diff " << diff << endl;
			if (diff <= maxDiff) {
				right++;
			} else {
				auto it = mySet.find(arr[right]);
				mySet.erase(it);
				break;
			}
		}

		res += right - left;
		// cout << "Çø¼ä" << left << " " << right << " " << diff << '\n';
		// for (auto elem : mySet) {
		// 	std::cout << elem << " ";
		// }
		// cout << endl;
		auto it = mySet.find(arr[left]);
		mySet.erase(it);
	}
	cout << res << endl;
	return res;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		solve();
	}

	return 0;
}
