#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<ar<int,2>> s;

    int n,m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int a;
        cin>> a;
        s.insert({a,i});
    }

    for(int i = 0;i < m; i++){
        int x;
        cin>>x;

        auto it = s.lower_bound({x+1,0});
        //cout<<(*it)[0]<<'\n';
        if(it == s.begin())
            cout<<-1<<'\n';
        else{
            --it;
            cout<<(*it)[0]<<'\n';
            s.erase(it);
        }
    }
    return 0;
}
