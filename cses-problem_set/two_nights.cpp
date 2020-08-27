#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cal(ll n){
    return (n*n*(n*n - 1) - 8 - 24 - 16*(n - 4) - 16 - 24 * (n - 4) - 8 * (n - 4)*(n - 4))/2;
}
int main(){
    ll k;
    cin>>k;
    for(ll i = 1; i <= k; i++){
        cout<<cal(i)<<'\n';
    }
    return 0;
}
