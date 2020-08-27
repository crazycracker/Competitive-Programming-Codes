#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,n;
    long long int x;
    long long int m=1000001;

    //generate prime numbers
    vector<bool> primes(1000001,true);
    set<long long int> st;
    primes[0]=primes[1]=false;

    //seive of eratosthenes
    for(i=2;i*i<=m;i++)
    {
        if(primes[i])
        {
            for(j=i;i*j<=m;j++)
            {
                primes[i*j]=false;
            }
        }
    }

    //put all the t_primes in the set
    for(i=2;i<=m;i++)
    {
        if(primes[i])
            st.insert(i*i);
    }

    cin>>n;

    while(n--)
    {
        cin>>x;

        if(st.find(x)!=st.end())
            cout<<"YES";
        else
            cout<<"NO";

        cout<<endl;
    }

    return 0;
}
