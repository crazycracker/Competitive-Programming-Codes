#include <bits/stdc++.h>
#define ll long long int
#define ar array

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        ll a[n] = {}, w[k] = {};

        for(int i = 0; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < k; i++)
            cin>>w[i];
        sort(a, a+n);
        sort(w, w+k, greater<int>());

        ll ans = 0;

        int l = 0, r = n-k;
        for(int i = 0; i < k; i++){
            if(w[i] == 1){
                ans += 2*a[r];
                r++;
            }else{
                ans += (a[l++] + a[r++]);
                l += w[i] - 2;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
