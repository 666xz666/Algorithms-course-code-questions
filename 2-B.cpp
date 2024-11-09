//八皇后
#include <bits/stdc++.h>
using namespace std;

bool check(int &i, int &j, int *queens)
{
    for (int u = 0; u < i; u++)
    {
        if (queens[u] == j || abs(queens[u] - j) == abs(u - i))
        {
            // There is a conflict with the previous queen
            // that means there is already a queen in the same row or diagonal
            // so we can't put a queen in this position
            // abs(queens[u] - j) == abs(u - i): means the queens are in the same diagonal
            // queens[u] == j: means the queens are in the same row
            return false;
        }
    }
    return true;
}

void backTracking(int a[8][8], int &sum, int &ans, int queens[8], int i = 0)
{
    // There must be a queen in every row
    if (i == 8)
    {
        ans = max(ans, sum);
        return;
    }

    for (int j = 0; j < 8; j++)
    {
        if (!check(i, j, queens))
            continue;

        queens[i] = j;
        sum += a[i][j];
        backTracking(a, sum, ans, queens, i + 1);
        sum -= a[i][j];
        queens[i] = -1;
    }
}

void work()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a[8][8];
        int ans = 0, sum = 0;
        int queens[8];
        for (int i = 0; i < 8; i++)
            queens[i] = -1;

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> a[i][j];

        backTracking(a, sum, ans, queens);

        cout << ans << endl;
    }
}

int main()
{
    work();
    return 0;
}