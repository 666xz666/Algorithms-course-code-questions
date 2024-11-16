// 快速幂
#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000007;

int fastpow(int base, int power)
{
    int res = 1;
    while (power > 0)
    {
        if (power % 2 == 0)
        {
            power /= 2;
            base = 1ll * base * base % MOD;
        }
        else
        {
            power -= 1;
            res = 1ll * res * base % MOD;
        }
    }

    return res;
}

void work()
{
    int n;
    while (cin >> n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum = (1ll * sum + fastpow(i, i)) % MOD;
        }
        cout << (1ll * sum + 1) % MOD << endl;
    }
}

int main()
{
    work();
    return 0;
}