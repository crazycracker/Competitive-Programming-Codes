#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

int compare(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int,int>> vec;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end());

    lli curr = 0,ans = 0;
    for(int i = 0; i < n; i++){
        curr += vec[i].first;
        ans += (vec[i].second - curr);
    }
    cout<<ans;
    return 0;
}
