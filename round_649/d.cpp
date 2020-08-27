#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005], col[2], s, cyc;
int pos[100005];

bool dfs(int node){
    pos[node] = s.size();
    col[pos[node]%2].push_back(node);
    s.push_back(node);

    int low = -1;

    for(int u: adj[node]){
        if(pos[u] != -1 && pos[node] - pos[u] > 1)
            low = max(low, pos[u]);
    }

    if(low != -1){
        for(int i = low; i <= pos[node]; i++){
            cyc.push_back(s[i]);
        }
        return 1;
    }

    for(int u: adj[node]){
        if(pos[u] == -1){
            if(dfs(u))
                return 1;
        }
    }
    s.pop_back();
    return 0;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(pos, -1, sizeof(pos));
    dfs(1);

    if(cyc.empty()){
        if(col[0].size() < col[1].size())
            swap(col[0], col[1]);
        cout<<"1"<<'\n';
        for(int i = 0; i < (k+1)/2; i++){
            cout<<col[0][i]<<' ';
        }
    }else{
        if(cyc.size() <= k){
            cout<<2<<'\n';
            cout<<cyc.size()<<'\n';
            for(int u: cyc)
                cout<<u<<' ';
        }else{
            cout<<1<<'\n';
            for(int i = 0;i < (k+1)/2; i++){
                cout<<cyc[2*i]<<' ';
            }
        }
    }
    return 0;
}
