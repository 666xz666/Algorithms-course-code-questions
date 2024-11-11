// algorithm-矩阵连乘

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Mat
{
    int l;
    int r;
};

// int n;
// int p[N];
// // int* p;
// int m[N][N];
// int s[N][N];
// string str[N][N];

// char numToChar(int x){
//     char c=x+'0';
//     return c;
// }

// string numToStr(int x){
//     string str;
//     if(x==0) return "0";

//     while(x!=0){
//         str=numToChar(x%10)+str;
//         x/=10;
//     }
//     return str;
// }

struct Solve
{
    int n;
    int p[N];
    // int* p;
    int m[N][N];
    int s[N][N];
    string str[N][N];

    char numToChar(int x)
    {
        char c = x + '0';
        return c;
    }

    string numToStr(int x)
    {
        string str;
        if (x == 0)
            return "0";

        while (x != 0)
        {
            str = numToChar(x % 10) + str;
            x /= 10;
        }
        return str;
    }

    void work(int &nn, int pp[N])
    {
        // cin>>n;
        // for(int i=0;i<=n;i++) cin>>p[i];
        n = nn;
        for (int i = 0; i <= n; i++)
            p[i] = pp[i];

        for (int i = 0; i < n; i++)
        {
            m[i][i] = 0;

            str[i][i] += numToStr(i);
        }

        for (int r = 2; r <= n; r++)
        {
            int i = 0, j = i + r - 1;
            while (j < n)
            {

                int mn = INT_MAX;
                int ss = -1;
                for (int k = i; k < j; k++)
                {
                    if (mn > m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1])
                    {
                        ss = k;
                        mn = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                    }
                }

                m[i][j] = mn;
                s[i][j] = ss;
                str[i][j] = "( " + str[i][ss] + " * " + str[ss + 1][j] + " )";

                cout << "m[" << i << "][" << j << "]:" << m[i][j] << endl;
                cout << "s[" << i << "][" << j << "]:" << s[i][j] << endl;

                i++;
                j++;
            }
        }

        cout << m[0][n - 1] << endl;
        cout << str[0][n - 1];
    }
};

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
        }

        p[i] = preR;

        Solve solve;
        // solve.work(n,p);
    }
}

int main()
{
    work();
    return 0;
}
