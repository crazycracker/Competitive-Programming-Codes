#include <bits/stdc++.h>

using namespace std;
int primeFactors(int n)
{
    int m = n;
    int cnt = 0;
    // Print the number of 2s that divide n
    if(n % 2 == 0)
        cnt++;
    while (n%2 == 0)
    {
        n = n/2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        if(n % i == 0)
            cnt++;
        while (n%i == 0)
        {
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int i = n; i < m; i++){
            ans += primeFactors(i);
        }
        cout<<ans<<endl;
    }
}
