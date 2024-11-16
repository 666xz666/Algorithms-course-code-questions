// Huffman
#include <bits/stdc++.h>
using namespace std;

#define CODING true // Give the Huffuman code result.

struct Node
{
    char c;
    int val;
    Node *left;
    Node *right;
    Node()
    {
        c = '*';
        left = right = nullptr;
    }
};

Node *CreateNode(Node *a, Node *b)
{
    int val = a->val + b->val;
    Node *p = new Node();
    p->val = val;
    p->left = a;
    p->right = b;
    return p;
}

struct Compare
{
    bool operator()(Node *a, Node *b) const
    {
        return a->val > b->val; // 最小堆
    }
};

void solve(Node *p, int &cnt, string &s, unordered_map<char, int> &mp, unordered_map<char, string> &mp1)
{
    if (p == nullptr)
        return;
    if (p->left == nullptr && p->right == nullptr)
    {
        mp[p->c] = cnt;
        mp1[p->c] = s;
    }
    cnt++;
    s += '0';
    solve(p->left, cnt, s, mp, mp1);
    s = s.substr(0, s.size() - 1);
    s += '1';
    solve(p->right, cnt, s, mp, mp1);
    s = s.substr(0, s.size() - 1);
    cnt--;
}

void work()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        unordered_map<char, int> countMap;
        for (char c : s)
        {
            if (!countMap.count(c))
                countMap[c] = 0;
            countMap[c]++;
        }

        priority_queue<Node *, vector<Node *>, Compare> qu; // 默认是最大堆，通过修改比较函数改成最小堆
        for (auto pr : countMap)
        {
            // cout<<pr.first<<" "<<pr.second<<endl;

            Node *p = new Node();
            p->c = pr.first;
            p->val = pr.second;
            qu.push(p);
        }

        while (qu.size() > 1)
        {
            Node *p1 = qu.top();
            qu.pop();
            Node *p2 = qu.top();
            qu.pop();
            // cout<<p1->val<<" "<<p2->val<<endl;
            qu.push(CreateNode(p1, p2));
        }

        int cnt = 0;
        string str = "";
        unordered_map<char, int> codeLenMap;
        unordered_map<char, string> codeMap;
        Node *p = qu.top();
        solve(p, cnt, str, codeLenMap, codeMap);

        int sum = 0;
        for (auto pr : countMap)
        {
            sum += codeLenMap[pr.first] * pr.second;
        }

        cout << sum << endl;
        if (CODING)
        {
            string ans = "";
            for (char c : s)
            {
                ans += codeMap[c] + ' ';
            }
            cout << ans << endl;
        }
    }
}

int main()
{
    work();
    return 0;
}