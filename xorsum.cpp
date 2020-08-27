#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    int n;
    cin>>n;

    long long int arr[n+1],pref[n+1];
    arr[0] = pref[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        pref[i] = pref[i-1]^arr[i];
    }
    int q,x,y;
    cin>>q>>x;

    while(q--){
        cin>>x>>y;
        int ans = 0;
        for(int i = x; i <= y-2; i++){
            for(int j = i + 1; j <= y-1; j++){
                int val2 = arr[i]^arr[j];
                for(int k = j + 1;k <= y; k++){
                   // cout<<i<<' '<<j<<' '<<k<<endl;
                    ans = (ans%mod + (val2^arr[k])%mod)%mod;
                }
            }
        }
        cout<<ans<<endl;
    }

}
