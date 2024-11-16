// 求第k小
#include <bits/stdc++.h>
using namespace std;

int findKth(vector<int> &v, int l, int r, int k)
{
    if (l == r)
        return v[l];

    int rd = rand() % (r - l + 1) + l;

    int val = v[rd];
    int ll = l;
    int rr = r;
    for (int i = l; i <= r; i++)
    {
        while (i <= rr && v[i] > val)
            swap(v[i], v[rr--]);
        if (v[i] < val)
            swap(v[i], v[ll++]);
    }
    int i = rr;

    if (k <= i - l + 1)
        return findKth(v, l, i, k);
    else
        return findKth(v, i + 1, r, k - (i - l + 1));
}

void work()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    srand(int(time(0)));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findKth(v, 0, v.size() - 1, k);
}

int main()
{
    work();
    return 0;
}