//进制转换
#include<bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin>>n;
    // cout<<pow(8,6);
    int i=7;
    while(n / (int)pow(8,i)==0)i--;
    // cout<<i<<endl;
    while(n!=0){
        cout<<n / (int)pow(8,i);
        n=n % (int)pow(8,i);
        i--;
    }
}

int main(){
    work();
    return 0;
}