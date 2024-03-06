#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
int a[N][N];        // 保存原数据
ll prefixSum[N][N]; // 保存前缀和

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    /*计算前缀和*/
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] + a[i][j] - prefixSum[i - 1][j - 1];
        }
    }
    int x1, x2, y1, y2;
    for (int i = 0; i < q; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        cout << prefixSum[x2][y2] + prefixSum[x1][y1] - prefixSum[x2][y1] - prefixSum[x1][y2] << '\n';
    }

    return 0;
}
