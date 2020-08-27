#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;

int main(){
    ll n, sum = 0;
    cin>>n;

    for(int i = 1; i < n; i++){
        ll x;
        cin>>x;
        sum += x;
    }
    cout<<((n*(n+1))/2 - sum)<<'\n';
    return 0;
}

