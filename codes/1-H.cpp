// 矩阵连乘

// 参考代码
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct mm
{
    int r;
    int c;
} ans[30];

string s;
int f[105][105];

void pre()
{
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < 105; ++i)
        f[i][i] = 0;
}

int dp()
{
    for (int j = 0; j < s.size() - 1; ++j)
        if (ans[s[j] - 'A'].c != ans[s[j + 1] - 'A'].r)
            return -1;
    for (int l = 2; l <= s.size(); ++l)
        for (int i = 0; i + l - 1 < s.size(); ++i)
        {
            int j = i + l - 1;
            for (int k = i; k < j; ++k)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + ans[s[i] - 'A'].r * ans[s[k] - 'A'].c * ans[s[j] - 'A'].c);
            }
        }
    return f[0][s.size() - 1];
}

int main()
{
    int n, m, x, y;
    char matrix;
    while (~scanf("%d%d", &n, &m))
    {
        while (n--)
        {
            cin >> matrix;
            scanf("%d%d", &x, &y);
            ans[matrix - 'A'].r = x;
            ans[matrix - 'A'].c = y;
        }

        while (m--)
        {
            cin >> s;
            pre();
            int t = dp();
            if (t == -1 || t == 1e18)
                puts("MengMengDa");
            else
                printf("%d\n", t);
        }
    }
    return 0;
}

// 50%
//  #include <bits/stdc++.h>
//  using namespace std;

// const int N = 1005;
// struct Mat
// {
//     int l;
//     int r;
// };

// int getMinCost(int p[], int n)
// {
//     // cout<<n<<endl;
//     // for(int i=0;i<=n;i++) cout<<p[i]<<" "<<endl;

//     int dp[N][N];
//     for (int i = 0; i < n; i++)
//         dp[i][i] = 0;

//     for (int k = 2; k <= n; k++)
//     {
//         for (int i = 0; i + k - 1 < n; i++)
//         {
//             int mn = INT_MAX;
//             for (int u = i; u < i + k - 1; u++)
//             {
//                 mn = min(mn, dp[i][u] + dp[u + 1][i + k - 1] + p[i] * p[u + 1] * p[(i + k - 1) + 1]);
//             }
//             dp[i][i + k - 1] = mn;
//         }
//     }
//     return dp[0][n - 1];
//     // return 0;
// }

// void work()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<char, Mat> mp;
//     for (int i = 0; i < n; i++)
//     {
//         Mat mat;
//         char c;
//         cin >> c >> mat.l >> mat.r;
//         mp[c] = mat;
//     }

//     while (m--)
//     {
//         string s;
//         cin >> s;
//         int preR = mp[s[0]].l;
//         int p[N];
//         int i = 0;
//         for (; i < s.size(); i++)
//         {
//             if (mp[s[i]].l != preR)
//                 break;
//             p[i] = mp[s[i]].l;
//             preR = mp[s[i]].r;
//         }

//         if (i != s.size())
//         {
//             cout << "MengMengDa" << endl;
//             continue;
//         }

//         p[i] = preR;

//         // for(int i=0;i<=s.size();i++) cout<<p[i]<<" ";cout<<endl;
//         cout << getMinCost(p, s.size()) << endl;
//     }
// }

// int main()
// {
//     work();
//     return 0;
// }
