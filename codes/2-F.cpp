// 迷宫游戏

// 参考代码
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f;
// priority_queue<int,vector<int>,greater<int>>q;

int n, m, s_r, e_r;
int val[550];
int maze[550][550];
int vis[550];
int tim[550];
int sum[550];

void dfs()
{
    int MIN, v;
    for (int i = 0; i < n; i++) // start find from room i
    {
        MIN = INF;
        v = 0;
        for (int j = 0; j < n; j++) // find the ith smallest time room v
        {
            if (!vis[j])
            {
                if (tim[j] < MIN)
                {
                    MIN = tim[j];
                    v = j;
                }
            }
        }
        vis[v] = 1;
        for (int j = 0; j < n; j++) // from room v to room j
        {
            if (!vis[j])
            {
                if (tim[j] > tim[v] + maze[v][j]) // get the smaller time
                {
                    tim[j] = tim[v] + maze[v][j];
                    sum[j] = sum[v] + val[j]; // get value when enter room j
                }
                else if (tim[j] == tim[v] + maze[v][j]) // equal condition,to get the bigger value
                {
                    sum[j] = max(sum[j], sum[v] + val[j]);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s_r >> e_r;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                maze[i][j] = 0;
            else
                maze[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        maze[x][y] = t;
        maze[y][x] = t;
    }
    memset(vis, 0, sizeof(vis));
    memset(tim, INF, sizeof(tim));
    memset(sum, 0, sizeof(sum));
    tim[s_r] = 0;
    sum[s_r] = val[s_r];
    dfs();
    cout << tim[e_r] << " " << sum[e_r] << endl;
    return 0;
}

// TLE
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