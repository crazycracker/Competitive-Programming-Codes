#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;

int main(){
    ll n;
    cin>>n;

    while(n != 1){
        cout<<n<<' ';
        n = (n % 2 == 0)? n/2: n * 3 + 1;
    }
    cout<<n<<'\n';
    return 0;
}
