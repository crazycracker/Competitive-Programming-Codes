#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n+1];
        arr[0] = 0;

        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            arr[i] = arr[i] + arr[i-1];
        }
        int q;
        cin>>q;

        for(int i = 0; i < q; i++){
            int a,b;
            cin>>a>>b;
            cout<<arr[b]-arr[a-1]<<endl;
        }
    }
}
