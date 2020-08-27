#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int p[20];

int main(){
    int n;
    cin>>n;

    ll sum, ans;
    sum = ans = 0;

    for(int i = 0;i < n; i++){
        cin>>p[i], sum += p[i];
    }

    for(int i = 0; i < 1<<n; i++){
        ll cs = 0;
        for(int j = 0; j < n; j++){
            if(i>>j&1){
                cs += p[j];
            }
        }

        if(cs <= sum/2)
            ans = max(ans, cs);
    }
    cout<<sum-2*ans<<'\n';
    return 0;
}
