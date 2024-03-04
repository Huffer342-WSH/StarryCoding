#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
ll a[N], diff[N], sum[N];

int main()
{
    int n, p, q;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> p >> q;

    /*输入数组*/
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    /*计算差分*/
    for (int i = 1; i <= n; i++)
    {
        diff[i] = a[i] - a[i - 1];
    }

    /*输入p次区间加操作*/
    for (int i = 0; i < p; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }
    /*更新数组*/
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + diff[i];
    }

    /*计算前缀和*/
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    /*输出q次区间和*/
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n';
    }
}

/*

in:
5 1 2
1 1 1 2 2
1 4 2
1 3
1 5

out:
9
15
*/
