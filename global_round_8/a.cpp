#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,n,counts = 0;
        cin>>a>>b>>n;

        if(a > b)
            swap(a,b);
        int c = 0;
        while(c <= n){
            c = b + a;
            a = b;
            b = c;
            //cout<<a<<' '<<b<<'\n';
            counts++;
        }
        cout<<counts<<'\n';
    }
}
