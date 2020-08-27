#include <bits/stdc++.h>

using namespace std;

int getOddPrimes(int n){
    long long int ans = 0;
    for(int i = 1; i <= n/2; i+=2){
        if(n % i == 0){
            ans += i;
        }
    }
    if(n % 2 == 1){
        ans += n;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int l, r;
        cin>>l>>r;

        long long int ans = 0;

        for(int i = l; i <= r; i++){
            ans += getOddPrimes(i);
        }

        cout<<ans<<endl;
    }
}
