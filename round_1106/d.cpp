#include <bits/stdc++.h>
#define N 300010

using namespace std;

vector<int> edges[N];
vector<int> seq;
bool vis[N];
priority_queue<int, vector<int> , greater<int> > Q;

int main(){
    int n,m,u,v;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    Q.push(1);
    vis[1] = true;

    while(!Q.empty()){
        int now = Q.top();
        Q.pop();
        seq.push_back(now);
        for(int p = 0; p < edges[now].size(); p++){
            if(!vis[edges[now][p]]){
                Q.push(edges[now][p]);
                vis[edges[now][p]] = true;
            }
        }
    }

    for(int i = 0; i < seq.size(); i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
    return 0;
}
