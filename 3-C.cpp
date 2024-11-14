// 简单密码 N

//dp压缩空间
/*
代码中使用了二维数组 dp 来存储状态，但实际上可以进一步优化空间复杂度。由于在计算 dp[i] 时只依赖于 dp[i-1] 的值，因此可以只使用一个一维数组来存储前一个状态，从而将空间复杂度从 O(n) 降低到 O(1)。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 35;

void work()
{
    int n;
    while (cin >> n)
    {
        if (n < 3)
        {
            cout << 0 << endl;
            continue;
        }

        //int dp[N][3]; // dp[i][j]表示长度为i的二进制串，末尾有j个0时，不出现连续3个0的情况数
        int dp0=4;// dp[3][0] = 4;
        int dp1=2;// dp[3][1] = 2;
        int dp2=1;// dp[3][2] = 1;

        for (int i = 4; i <= n; i++)
        {
//             dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
//             dp[i][1] = dp[i - 1][0];
//             dp[i][2] = dp[i - 1][1];

            int tmp0 = dp0 + dp1 + dp2;
            int tmp1 = dp0;
            int tmp2 = dp1;

            dp0=tmp0,dp1=tmp1,dp2=tmp2;
        }

//         cout << (1 << n) - (dp[n][0] + dp[n][1] + dp[n][2]) << endl;
        cout << (1 << n) - (dp0 + dp1 + dp2) << endl;
    }
}

int main()
{
    work();
    return 0;
}

//dp
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 35;

// void work()
// {
//     int n;
//     while (cin >> n)
//     {
//         if (n < 3)
//         {
//             cout << 0 << endl;
//             continue;
//         }

//         int dp[N][3]; // dp[i][j]表示长度为i的二进制串，末尾有j个0时，不出现连续3个0的情况数
//         dp[3][0] = 4;
//         dp[3][1] = 2;
//         dp[3][2] = 1;

//         for (int i = 4; i <= n; i++)
//         {
//             dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
//             dp[i][1] = dp[i - 1][0];
//             dp[i][2] = dp[i - 1][1];
//         }

//         cout << (1 << n) - (dp[n][0] + dp[n][1] + dp[n][2]) << endl;
//     }
// }

// int main()
// {
//     work();
//     return 0;
// }

// 回溯 N
//  #include<bits/stdc++.h>
//  using namespace std;

// int n;
// void backTracking(long long& ans,int& pre,int i=0){
//     if(i>n) return;
//     if(pre==3){
//         ans+=1ll<<n-i;
//         return;
//     }
//     //0
//     pre++;
//     backTracking(ans,pre,i+1);
//     //1
//     pre=0;
//     backTracking(ans,pre,i+1);
// }

// void work(){
//     while(cin>>n){
//         long long ans=0;
//         int pre=0;
//         backTracking(ans,pre);
//         cout<<ans<<endl;
//     }
// }

// int main(){
//     work();

//     return 0;
// }