// 迷宫游戏 TLE

#include <bits/stdc++.h>
using namespace std;

const int INF = 300 * 600;

int n, m, sta, ed;
int score[505];
int dis[505][505];
int lowCost[505];
int value[505];
int last[505];

void work()
{
    cin >> n >> m >> sta >> ed;
    for (int i = 0; i < n; i++)
        cin >> score[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = dis[y][x] = z;
    }

    unordered_set<int> st;
    st.insert(sta);
    for (int i = 0; i < n; i++)
    {
        last[i] = sta;
        value[i] = 0;
        lowCost[i] = INF;
    }
    lowCost[sta] = 0;
    int pre = sta;
    value[sta] = score[sta];
    while (st.size() != n)
    {
        int mn = INF;
        int mni = -1;
        for (int i = 0; i < n; i++)
        {
            if (st.find(i) != st.end())
                continue;
            if (lowCost[pre] + dis[pre][i] < lowCost[i] || (lowCost[pre] + dis[pre][i] == lowCost[i] && value[pre] + score[i] > value[i]))
            {
                lowCost[i] = lowCost[pre] + dis[pre][i];
                last[i] = pre;
                value[i] = value[pre] + score[i];

                if (lowCost[i] < mn || (lowCost[i] == mn && score[i] > score[mni]))
                {
                    mn = lowCost[i];
                    mni = i;
                }
            }
        }

        st.insert(mni);
        pre = mni;
    }

    int i = ed;
    while (i != sta)
    {
        cout << i << " ";
        i = last[i];
    }
    cout << i << endl;

    cout << lowCost[ed] << " " << value[ed] << endl;
}

int main()
{
    work();
    return 0;
}