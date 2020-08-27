#include <bits/stdc++.h>

using namespace std;

int  main(){
    string path = "DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD";

    sort(path.begin(), path.end());

    int cnt[26];

    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < (int)path.length(); i++){
        cnt[path[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            cout<<i+'A'<<' '<<cnt[i]<<'\n';
        }
    }

}
