#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;


int main(){

    int n;
    cin>>n;

    ll ans = 0, prev, x;
    cin>>prev;

    for(int i = 1; i < n; i++){
        cin>>x;
        if(x < prev){
            ans += abs(prev - x);
            prev = x + abs(prev - x);
        }else{
            prev = x;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

