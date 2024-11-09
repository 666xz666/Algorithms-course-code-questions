#include<bits/stdc++.h>
using namespace std;

void permute(string &str,int u){
    if(u==str.size()){
        cout<<str<<" ";
        return ;
    }

    sort(str.begin()+u,str.end());

    for(int i=u;i<str.size();i++){
        swap(str[u],str[i]);
        permute(str,u+1);
        swap(str[u],str[i]);
    }
}

void work(){
    string str;
    cin>>str;
    str.pop_back();

    permute(str,0);
}

int main(){
    work();
    return 0;
}