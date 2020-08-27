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

    int n;
    cin>>n;

    set<ar<int,2>> s;

    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        s.insert({a,1});
        s.insert({b,-1});
    }
    int ans = 0, c = 0;
    for(ar<int,2> a: s){
        c += a[1];
        ans = max(ans, c);
    }
    cout<<ans<<'\n';
    return 0;
}
