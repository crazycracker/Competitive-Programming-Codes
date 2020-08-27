#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        if(n % 2 == 0 && m % 2 == 0){
            cout<<n/2 * m <<'\n';
        }else{
            if(n % 2 == 0 && m % 2 != 0){
                cout<<n/2 * m <<'\n';
            }else if(n % 2 != 0 && m % 2 == 0){
                cout<<n * m/2<<'\n';
            }else{
                if(n > m){
                    int temp = n;
                    n = m;
                    m = temp;
                }
                cout<<(n-1)/2 * m + m/2 + 1<<'\n';
            }
        }
    }
    return 0;
}
