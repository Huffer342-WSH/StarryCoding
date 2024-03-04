/*
https://www.starrycoding.com/problem/7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100005

ll prefixSum[MAX];
void solve()
{
    int arraySize, questionNum;
    ll sum = 0;
    prefixSum[0] = 0;
    /*输入 数组长度、前缀和询问次数*/
    cin >> arraySize >> questionNum;

    /*输入数组，并计算前缀和*/
    for (int i = 1; i <= arraySize; i++)
    {
        ll t;
        cin >> t;
        sum += t;
        prefixSum[i] = sum;
    }

    /*输入问题，并回答*/
    for (int i = 0; i < questionNum; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a - 1] << '\n';
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int testNum;
    cin >> testNum;
    for (int i = 0; i < testNum; i++)
    {
        solve();
    }
    return 0;
}
/*

in:
2
5 3
1 2 3 4 5
1 2
2 5
3 4
7 2
-1 9 -10 8 2 6 11
1 5
2 7

out:
3
14
7
8
26

*/
