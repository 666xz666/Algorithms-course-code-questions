//跳台阶
#include<bits/stdc++.h>
using namespace std;

const int N=105;
const int MOD = 1000000007;

void work(){
    int n;
    while(cin>>n){
        int f[N];
        f[1] = 1;
        f[2] = 2;
        if(n == 1 || n == 2){
            cout << n << endl;
            continue;
        } 
        for(int i = 3;i <= n;i++){
            f[i] = ( 1ll * f[i-1] + f[i-2] ) % MOD;
        }

        cout << f[n] << endl;
}

}


int main(){
    work();
    return 0;
}