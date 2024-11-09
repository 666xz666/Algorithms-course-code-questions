//汽车费用
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 读取1到10公里的费用
    vector<int> costs(10);
    for (int i = 0; i < 10; ++i) {
        cin >> costs[i];
    }

    // 读取总路程n
    int n;
    cin >> n;

    // 初始化dp数组，dp[i]表示到达第i公里的最小费用
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; // 到达0公里的费用为0
    // 动态规划填表
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + costs[j - 1]);
            }
        }
    }

    // 输出到达n公里的最小费用
    cout << dp[n] << endl;

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int fee[11];
// int n;

// void work(){
//     for(int i=1;i<11;i++) cin>>fee[i];
//     cin>>n;


// }

// int main(){
//     work();
//     return 0;
// }