#include <bits/stdc++.h>

using namespace std;

bool myfunction(pair<int,int> i, pair<int,int> j){
    return (i.first > j.first);
}
int main(){
    int n;
    cin>>n;

    vector< pair<int,int> > a(n) ,b(n);

    for(int i = 0;i < n; i++){
        int x;
        cin>>x;
        a[i] = make_pair(x,i);
    }
    for(int i = 0;i < n; i++){
        int x;
        cin>>x;
        b[i] = make_pair(x,i);
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[b[i].second] = a[i].first;
    }
    for(int i = 0; i < n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}
