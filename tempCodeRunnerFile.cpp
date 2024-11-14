// 矩阵连乘
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
struct Mat
{
    int l;
    int r;
};

int getMinCost(int p[], int n)
{   
    // cout<<n<<endl;
    // for(int i=0;i<=n;i++) cout<<p[i]<<" "<<endl;

    int dp[N][N];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i + k - 1 < n; i++)
        {
            int mn = INT_MAX;
            for (int u = i; u < i + k - 1; u++)
            {
                mn = min(mn, dp[i][u] + dp[u + 1][i + k - 1] + p[i] * p[u + 1] * p[(i + k - 1) + 1]);
            }
            dp[i][i + k - 1] = mn;
        }
    }
    return dp[0][n - 1];
    // return 0;
}



void work()
{
    int n, m;
    cin >> n >> m;

    unordered_map<char, Mat> mp;
    for (int i = 0; i < n; i++)
    {
        Mat mat;
        char c;
        cin >> c >> mat.l >> mat.r;
        mp[c] = mat;
    }

    while (m--)
    {
        string s;
        cin >> s;
        int preR = mp[s[0]].l;
        int p[N];
        int i = 0;
        for (; i < s.size(); i++)
        {
            if (mp[s[i]].l != preR)
                break;
            p[i] = mp[s[i]].l;
            preR = mp[s[i]].r;
        }

        if (i != s.size())
        {
            cout << "MengMengDa" << endl;
            continue;
        }

        p[i] = preR;

        // for(int i=0;i<=s.size();i++) cout<<p[i]<<" ";cout<<endl;
        cout << getMinCost(p, s.size()) << endl;
    }
}

int main()
{
    work();
    return 0;
}


