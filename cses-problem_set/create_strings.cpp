#include <bits/stdc++.h>

using namespace std;

set<string, less <string> > sett;

void permute(string str, int l, int r){
    if(l == r){
        if(sett.find(str) == sett.end()){
            sett.insert(str);
        }
    }else{
        for(int i = l; i <= r; i++){
            swap(str[l], str[i]);
            permute(str, l+1, r);
            swap(str[i], str[l]);

        }
    }
    return;
}
int fact(int n){
    if(n == 1 || n == 0)
        return 1;
    return n * fact(n-1);
}
int main(){
    string str;
    cin>>str;

    int n = str.length();

    sort(str.begin(), str.end());

    int ch[26];

    memset(ch, 0, sizeof(ch));

    for(int i = 0; i < n; i++){
        ch[str[i]-'a']++;
    }
    int deno = 1;

    for(int i = 0; i < 26; i++){
        deno *= fact(ch[i]);
    }
    cout<<fact(n)/deno<<'\n';
    permute(str, 0, n-1);
    for(set<string>::iterator it = sett.begin(); it != sett.end(); it++)
        cout<< *it <<'\n';
    return 0;
}
