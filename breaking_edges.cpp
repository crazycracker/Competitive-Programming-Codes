#include <bits/stdc++.h>
using namespace std;
int arr[200000];
vector<int> adj[200000];

int main(){
    int n,u,v;
    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int temp = 0;

    for(int i = 0; i < n; i++){
        temp = temp | arr[i];
        cout<<temp<<" ";
    }
    cout<<endl;
    temp = 0;
    for(int i = n-1; i >= 0; i--){
        temp = temp | arr[i];
        cout<<temp<<" ";
    }
    cout<<endl;
}
