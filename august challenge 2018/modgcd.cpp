#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long int a,b,n;
        cin>>a>>b>>n;

        if(a == b || a == 0 || b == 0)
            cout<<a<<endl;
        else{
            long long int res = pow(a,n) + pow(b,n),n1,n2;
            n1 = res;
            n2 = abs(a-b);
            while(n1!=n2)
            {
                if(n1 > n2)
                    n1 -= n2;
                else
                    n2 -= n1;
            }
            cout<<(n1%mod)<<endl;
        }
    }
    return 0;
}
