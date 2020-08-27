#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,cnt=0;
        cin>>n>>m;

        int arr[n];

        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] % m == 0)
                cnt++;
        }
        cout<<(long long int )(pow(2,cnt) - 1)<<endl;
    }
    return 0;
}
