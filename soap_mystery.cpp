#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n,q,m;
    cin>>n;

    vector<long long int> vec;

    for(int i = 0; i < n; i++)
    {
        cin>>q;
        vec.push_back(q);
    }
    sort(vec.begin(),vec.end());
    cin>>q;

    while(q--){
        cin>>m;
        cout<<(lower_bound(vec.begin(),vec.end(),m)-vec.begin())<<endl;
    }
}