#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long int power(long long int x, long long int y)
{
    long long int res = 1;      // Initialize result

    x = x % mod;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res;
}

double sumOfGP(long long int a, long long int r, long long int n)
{
    // calculating and storing sum
    return (a * (1 - power(r, n))) / (1 - r);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n,k;
        cin>>n>>k;
        if(k == 1){
            cout<<n<<endl;
        }else{
            cout<<(long long int)(sumOfGP(k,k,n))%mod<<endl;
        }
    }
}
