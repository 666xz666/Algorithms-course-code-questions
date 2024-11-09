//凯撒加密
#include<bits/stdc++.h>
using namespace std;

int k;
string str;

int type(char ch){
    if(ch>='a'&&ch<='z') return 1;
    else if(ch>='A'&&ch<='Z') return 2;
    else return 0;
}

void coding(string& str){
    for(int i=0;i<str.size();i++){
        char chA='a';
        if(type(str[i])==0) continue;
        if (type(str[i])==2) chA='A';

        int idx=str[i]-chA;
        k%=26;
        idx=(idx-k+26)%26;
        str[i]=chA+idx;
    }
}

void work(){
    int t;
    cin>>t;
    while(t--){
        cin>>str>>k;
        
        coding(str);

        cout<<str<<endl;
    }
}

int main(){

    work();

    return 0;
}