//法师康

#include <bits/stdc++.h>
using namespace std;

struct Worker
{
    int sta;
    int end;

    bool operator<(const Worker &w) const
    {
        if (sta == w.sta)
            return end < w.end;
        else
            return sta < w.sta;
    }
};

int n;

void work()
{
    cin >> n;
    vector<Worker> v;

    for (int i = 0; i < n; i++)
    {
        Worker w;
        cin >> w.sta >> w.end;
        v.emplace_back(w);
    }

    sort(v.begin(), v.end());

    int workMaxTime = 0;
    int freeMaxTime = 0;

    /*
    排查发现  int workMaxTime=INT_MIN;
    int freeMaxTime=INT_MIN;导致错误!!!!!!!!!!!!!!!!!!!!

    如果它们被初始化为 INT_MIN，那么在比较时可能会出现以下问题：

    溢出问题：
    当 workMaxTime 或 freeMaxTime 与一个正数进行 max 函数比较时，如果 INT_MIN 是16位整数的最小值，那么任何正数都会比 INT_MIN 大，这本身没有问题。但是，如果 workMaxTime 或 freeMaxTime 被更新为一个正数值，再次与 INT_MIN 比较时，由于 INT_MIN 的值非常小，可能会导致整数溢出，尤其是在 max 函数中。

    逻辑错误：
    在你的代码逻辑中，workMaxTime 和 freeMaxTime 应该存储的是时间段的长度，即非负整数。使用 INT_MIN 作为初始值在逻辑上不合适，因为时间段的长度不可能是负数.

    比较问题：
    在循环中，你使用 max 函数来更新 workMaxTime 和 freeMaxTime。如果 workMaxTime 或 freeMaxTime 的值是 INT_MIN，那么即使比较的另一个值是0（代表没有工作时间或空闲时间），max 函数也会返回 INT_MIN，因为 INT_MIN 小于0。这显然是错误的，因为时间段的长度至少是0。

    正确的做法是将 workMaxTime 和 freeMaxTime 初始化为0，因为0是时间段长度的最小非负值。这样，无论何时更新这些变量，都能保证它们的值是正确的非负整数，并且可以正确地与任何时间段长度进行比较。
    */

    int s = v[0].sta, e = v[0].end;
    int i = 0;
    while (i < v.size())
    {
        if (v[i].sta > e)
        {
            workMaxTime = max(workMaxTime, e - s);
            freeMaxTime = max(freeMaxTime, v[i].sta - e);
            s = v[i].sta;
            e = v[i].end;
        }
        else
        {
            e = max(e, v[i].end);
        }

        ++i;
    }

    workMaxTime = max(workMaxTime, e - s); // Update workMaxTime after the loop

    cout << workMaxTime << " " << freeMaxTime;
}

int main()
{
    work();
    return 0;
}