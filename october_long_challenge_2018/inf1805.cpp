#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;


        cin>>n>>q;

        long long int arr[n];

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }


        while(q--){
            int k;
            cin>>k;
            long long int sum = 0;
            sum = arr[0];

            for(int i = k + 1; i < n; i += k+1){
                sum += arr[i];
            }

            cout<<sum<<endl;
        }
    }
}
