// 最长公共子序列

#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

void work()
{
    string str1, str2;
    cin >> str1 >> str2;
    const int len1 = str1.size(), len2 = str2.size();

    int dp[N][N];
    dp[0][0] = 0;
    for (int i = 1; i <= len1; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= len2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1]) // 下标对应减一
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    cout << dp[len1][len2];
}

int main()
{
    work();
    return 0;
}