#include<bits/stdc++.h>
using namespace std;
string AlphabetOrderDiv2(vector<string> v){
    vector< set<char> > parents(26);
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size()-1;j++){
            char x=v[i][j];
            char y=v[i][j+1];
            if(x==y) continue;
            if(parents[x-'a'].count(y)>0) return "Impossible";
            parents[y-'a'].insert(x);
            if(parents[x-'a'].size()!=0){
                parents[y-'a'].insert(parents[x-'a'].begin(),parents[x-'a'].end());
            }
        }
    }
    return "possible";
}
int main(){
    //cout<< " enter strings"<<"\n";
    string s;
    vector<string> v;
    while(cin>>s){
        v.push_back(s);
    }
    cout<<AlphabetOrderDiv2(v);
}
