#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x,l=-1;
        cin>>n>>x;

        long long sum = 0;

        for(int i = 0;i < n; i++){
            int temp;
            cin>>temp;

            sum += temp;
            if(sum % x){
                l = max(l, max(i+1,n-(i+1)));
            }
        }
        cout<<l<<'\n';
    }

    return 0;
}
