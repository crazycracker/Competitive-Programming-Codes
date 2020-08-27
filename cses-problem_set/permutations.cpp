#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;

int main(){
    ll n,start;
    cin>>n;

    if(n == 1)
    {
        cout<<1<<'\n';
        return 0;
    }
    if(n >= 2 && n <= 3)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    if(n % 2)
        start = n - 1;
    else
        start = n;
    while(start != 4){
        cout<<start<<' ';
        start -= 2;
    }
    cout<<"2 4 ";
    start = 1;
    int e = (n % 2 == 0)? n - 1: n;

    while(start < e+1){
        cout<<start<<' ';
        start += 2;
    }
    cout<<'\n';
    return 0;
}
