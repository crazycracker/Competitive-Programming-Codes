#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    long long x;
    cin>>x;

    map<int,int> mapp;

    for(int i = 0 ; i < n; i++){
        int a;
        cin>>a;

        if(mapp.find(x - a) != mapp.end()){
            cout<<mapp[x-a]+1<<' '<<i+1<<'\n';
            return 0;
        }
        mapp[a] = i;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
