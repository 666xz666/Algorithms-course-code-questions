//排列问题 N
#include<bits/stdc++.h>
using namespace std;

void permute(string &str,int u,unordered_set<string>&set){
    if(u==str.size()){
        if(set.find(str)==set.end()){
            cout<<str<<" ";
            set.insert(str);
        }
        return;
    }

    sort(str.begin()+u,str.end());

    for(int i=u;i<str.size();i++){
        swap(str[u],str[i]);
        permute(str,u+1,set);
        swap(str[u],str[i]);
    }
}

void work(){
    string str;
    cin>>str;
    str.pop_back();
    unordered_set<string> set;
    permute(str,0,set);
}

int main(){
    work();
    return 0;
}



