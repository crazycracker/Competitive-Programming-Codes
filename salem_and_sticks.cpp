#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n);

    int t,minCost;

    minCost = INT_MAX;

    for(int i = 0; i <= arr[n-1]; i++){
        int val = 0;
        for(int j = 0; j < n; j++){
            val += abs(arr[j] - i);
        }
        if(val < minCost){
            t = i;
            minCost = val;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(abs(arr[i]-t) > 1){
            if(arr[i] < t)
                ans += abs((t-1) - arr[i] - 1);
            else
                ans += abs(t-arr[i]);
        }
    }
    cout<<(t-1)<<" "<<ans<<endl;
}
