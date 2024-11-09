//Homework 贪心
#include<bits/stdc++.h>
using namespace std;

struct tp{
    int t;
    int v;
};

void work(int m,int n){
    vector<tp> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i].t>>v[i].v;
    }

    //lambda
    sort(v.begin(),v.end(),[](const tp&a,const tp&b){
        return (double)a.v / a.t > (double)b.v / b.t;
    });

    double sum=0;
    for(int i=0;i<m;i++){
        if(n>v[i].t){
            n -= v[i].t;
            sum += v[i].v;
        }else{
            sum+=(double)v[i].v / v[i].t * n;
            break;
        }
    }

    printf("%.2f\n", sum); 
}

int main(){
    while(true){
        int m,n;
        cin>>m>>n;
        if(m==0&&n==0) break;
        work(m,n);
    }
    return 0;
}