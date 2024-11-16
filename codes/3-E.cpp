// 数据加密

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, tip, top;
string s;
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        cin >> s;
        tip = 0;
        top = n - 1;
        while (tip <= top)
        {
            if (s[tip] < s[top])
            {
                cout << s[tip];
                tip++;
            }
            else if (s[tip] > s[top])
            {
                cout << s[top];
                top--;
            }
            else
            {
                int ti = tip, to = top, f = 0;
                while (ti <= to)
                {
                    ti++;
                    to--;
                    if (s[ti] < s[to])
                    {
                        f = 0;
                        break;
                    }
                    else if (s[ti] > s[to])
                    {
                        f = 1;
                        break;
                    }
                }
                if (f)
                {
                    cout << s[top];
                    top--;
                }
                else
                {
                    cout << s[tip];
                    tip++;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

// 贪心 N 应该不是-_-
//  #include<bits/stdc++.h>
//  using namespace std;

// int n;
// string s;

// void work(){
//     while(cin>>n>>s){
//         string t;
//         int l=0,r=n-1;
//         while(l<=r){
//             if(s[l]<s[r]) t+=s[l++];
//             else t+=s[r--];
//         }
//         cout<<t<<endl;
//     }
// }

// int main(){
//     work();
//     return 0;
// }