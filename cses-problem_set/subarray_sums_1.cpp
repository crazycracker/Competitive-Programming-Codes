#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

const int maxn = 2e5;

int n;
lli x;
lli arr[maxn],prefix[maxn],counts;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;

    map<lli,int> mp;
    mp[0]++;
    lli s = 0;
    lli ans = 0;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        s += arr[i];
        ans += mp[s-x];
        mp[s]++;
    }

    cout<<ans;
    return 0;
}

