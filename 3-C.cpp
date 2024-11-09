//简单密码 N


//回溯
// #include<bits/stdc++.h>
// using namespace std;

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