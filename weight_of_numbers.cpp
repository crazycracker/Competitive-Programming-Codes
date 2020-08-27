#include <bits/stdc++.h>
#define M 1000000007
#define ll long long int

using namespace std;

ll power(ll base, ll exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % M;
        exponent = exponent >> 1;
        base = (base * base) % M;
    }

    return result;
}

int main(){
    int t;
    cin>>t;

    int baseArray[302],negativeArray[302];
    memset(baseArray,0,sizeof(baseArray));
    memset(negativeArray,0,sizeof(negativeArray));

    baseArray[0] = 9;
    for(int i = 1; i < 9; i++)
        baseArray[i] = 9-i;
    for(int i = 1; i < 10; i++){
        negativeArray[i] = 10 - i;
    }

    while(t--){
        long long int n,w;
        cin>>n>>w;
        long long int res = power(10,n-2),ans = 0;
        if(w >= 0)
            ans = ( baseArray[abs(w)]*res)%M;
        else
            ans = (negativeArray[abs(w)]*res)%M;
        cout<<ans<<endl;
    }
    return 0;
}
