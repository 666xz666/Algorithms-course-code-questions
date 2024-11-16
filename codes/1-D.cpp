// 排列问题
#include <bits/stdc++.h>
using namespace std;

set<string> Set;

void permute(string &str, int st = 0)
{
    if (st == str.size())
    {
        // cout<<str<<" ";
        Set.insert(str);
    }

    for (int i = st; i < str.size(); i++)
    {
        swap(str[i], str[st]);
        permute(str, st + 1);
        swap(str[i], str[st]);
    }
}

void work()
{
    string str;
    cin >> str;
    str = str.substr(0, str.size() - 1); // 去掉,
    sort(str.begin(), str.end());        // 按字典序排序
    permute(str);
    for (string _str : Set)
    {
        cout << _str << " ";
    }
}

int main()
{
    work();
    return 0;
}