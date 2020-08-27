#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    long long int n, ans = 1;
    cin>>n;

    for(int i = 1; i <= n; i++){
        ans *= 2;
        ans %= mod;
    }
    cout<<ans<<'\n';
    return 0;
}
