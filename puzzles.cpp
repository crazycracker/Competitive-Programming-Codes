#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr[m];

    for(int i = 0; i < m; i++)
        cin>>arr[i];
    sort(arr,arr+m);

    int ans = INT_MAX;

    for(int i = 0,j=n-1; j < m; i++,j++){
        int k = arr[j] - arr[i];
        if(k < ans)
            ans = k;
    }

    cout<<ans<<endl;
}
