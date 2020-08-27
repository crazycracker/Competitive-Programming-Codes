#include <bits/stdc++.h>

using namespace std;

map<string,int> mapp;

bool isSafe(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int ans = 0;
void func(pair<int,int> p, int n, int m, string str,string temp,string s[], bool right,int index){
    temp += s[p.first][p.second];
    if(temp.length() == str.length()){
        if(temp.compare(str) == 0)
            ans++;
        return;
    }
    if(isSafe(p.first,p.second+1,n,m) && right){
        if(str[index] == s[p.first][p.second+1])
            func({p.first,p.second+1},n,m,str,temp,s,true,index+1);
    }
    if(isSafe(p.first+1,p.second,n,m)){
        if(str[index] == s[p.first+1][p.second])
            func({p.first+1,p.second},n,m,str,temp,s,false,index+1);
    }
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    string s[n];

    for(int i = 0; i < n; i++)
        cin>>s[i];

    vector< vector<pair<int,int> > > vec;
    vec.resize(26);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vec[s[i][j] - 'A'].push_back(make_pair(i,j));
        }
    }
    /*for(int i = 0; i < 26; i++){
        for(int j = 0; j < vec[i].size(); j++)
        {
            pair<int,int> p = vec[i][j];
            cout<<p.first<<' '<<p.second<<'\n';
        }
        cout<<"----"<<'\n';
    }*/
    while(q--){
        string str;
        cin>>str;

        if(str.length() == 1){
            cout<<vec[str[0]-'A'].size()<<'\n';
        }else{
            ans = 0;
            for(int i = 0; i < vec[str[0]-'A'].size(); i++){
                pair<int,int> p = vec[str[0]-'A'][i];
                //cout<<p.first<<' '<<p.second<<'\n';
                func(p,n,m,str,"",s,true,1);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
