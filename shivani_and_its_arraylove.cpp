#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    arr[0] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        if(arr[i] <= k){
            cnt++;
        }
        arr[i] += arr[i-1];
    }

    for(int i = 1;i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(arr[j] - arr[i-1] <= k)
                cnt++;
        }
    }

    cout<<cnt<<endl;
}
