#include <bits/stdc++.h>
#define LL long long int
#define mod 1000000007
using namespace std;

const int MAX = 100000 + 1;

int n,m;
int totalPower = 0;
map< pair<int,int> , int> mapp;

void dfs(int sx, int sy, LL val){
    if(sx == n){
        for(int i = sy; i <= m; i++){
            val = (val + mapp[{sx,i}])%mod;
            if(val < 0)
                val = (val + mod)%mod;
        }
        totalPower = (totalPower + val)%mod;
        if(totalPower < 0)
            totalPower = (totalPower + mod)%mod;
        return;
    }

    if(sy == m){
        for(int i = sx; i <= n; i++){
            val = (val + mapp[{i,sy}])%mod;
            if(val < 0)
                val = (val + mod)%mod;
        }
        totalPower = (totalPower + val)%mod;
        if(totalPower < 0)
            totalPower = (totalPower + mod)%mod;
        return;
    }

    val = (val + mapp[{sx,sy}])%mod;

    if(val < 0)
        val = (val + mod)%mod;
    dfs(sx,sy+1,val);
    dfs(sx+1,sy,val);
}
int main(){
    int t;
    cin>>t;

    while(t--){
        mapp.clear();
        cin>>n>>m;
        int k;
        cin>>k;
        totalPower = 0;
        for(int i = 0; i < k; i++){
            int x,y,val;
            cin>>x>>y>>val;
            mapp[make_pair(x,y)] = val;
        }

        dfs(1,1,0);
        cout<<totalPower<<endl;
    }
}
