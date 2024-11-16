// 锯木棒
// 贪心 贪得没边
#include <bits/stdc++.h>
using namespace std;

void work()
{
    int n, l;
    cin >> n >> l;
    priority_queue<int, vector<int>, greater<int>> hp;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        hp.push(tmp);
    }

    int sum = 0;
    while (hp.size() > 1)
    {
        int tmp = 0;
        tmp += hp.top();
        hp.pop();
        tmp += hp.top();
        hp.pop();
        sum += tmp;
        hp.push(tmp);
    }

    cout << sum << endl;
}

int main()
{
    work();
    return 0;
}