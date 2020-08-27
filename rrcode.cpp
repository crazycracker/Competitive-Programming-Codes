#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n,k,ans;
        cin>>n>>k>>ans;

        long long int arr[n];
        long long int x, o, a;

        cin>>arr[0];
        x = o = a = arr[0];

        for(int i = 1; i < n; i++){
            cin>>arr[i];
            x ^= arr[i];
            o |= arr[i];
            a &= arr[i];
        }

        string oper;
        cin>>oper;

        if(oper == "XOR"){
            if(k % 2 == 0){
                cout<<(ans ^ 0)<<endl;
            }else{
                cout<<(ans ^ x)<<endl;
            }
        }else if(oper == "OR"){
            if(k != 0)
                cout<<(ans | o)<<endl;
            else
                cout<<ans<<endl;
        }else{
            if(k!= 0)
                cout<<(ans & a)<<endl;
            else
                cout<<ans<<endl;
        }
    }

    return 0;
}
