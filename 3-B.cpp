//vi什么什么 密码
#include<bits/stdc++.h>
using namespace std;

string k,str;

int getChA(char ch){
    if(ch>='A'&&ch<='Z') return 'A';
    else if(ch>='a'&&ch<='z') return 'a';
    else return '@';
}

void work(){
    cin>>k>>str;

    int i=0;
    int j=0;
    while(i<str.size()){
        char chA=getChA(str[i]);
        char chAK=getChA(k[j]);

        str[i]=chA+((str[i]-chA)-(k[j]-chAK)+26)%26;

        i++;
        j=(j+1)%k.size();            
    }

    cout<<str;
}

int main(){

    work();

    return 0;
}