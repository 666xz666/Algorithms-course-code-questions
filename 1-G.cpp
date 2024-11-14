// 沙子的质量
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1005;
int a[N];
int prefixes[N];
int getMinCost(int a[], int i, int j)
{
    if (i == j)
        return 0;

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        mn = min(mn, getMinCost(a, i, k) + getMinCost(a, k + 1, j) + prefixes[j] - prefixes[i - 1]);
    }
    return mn;
}

int dp[N][N];
int getMinCost_dp(int a[], int i, int j)
{
    // parameters i,j not used

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i + k - 1 < n; i++)
        {
            // dp[i][i+k-1]
            int mn = INT_MAX;
            for (int u = i; u < i + k - 1; u++)
            {
                mn = min(mn, dp[i][u] + dp[u + 1][i + k - 1] + prefixes[i + k - 1] - prefixes[i - 1]);
            }
            dp[i][i + k - 1] = mn;
        }
    }
    return dp[0][n - 1];
}

void work()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    prefixes[0] = a[0];
    for (int i = 0; i < n; i++)
        prefixes[i] = prefixes[i - 1] + a[i];
    cout << getMinCost_dp(a, 0, n - 1) << endl;
}

int main()
{
    work();
    return 0;
}