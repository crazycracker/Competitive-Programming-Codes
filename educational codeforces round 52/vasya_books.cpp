#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n],steps[n],maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        maxi = max(arr[i],maxi);
    }
    for(int i = 0; i < n; i++)
        cin>>steps[i];

    int ans = 0,k = 0,i = 0;
    bool pres[maxi+1];

    memset(pres,true,sizeof(pres));

    while(k < n){
        ans = 0;
        if(pres[steps[k]]){
            while(i < n && steps[k] != arr[i]){
               pres[arr[i]] = false;
               i++;
               ans++;
            }
            if(steps[k] == arr[i]){
                pres[arr[i]] = false;
                i++;
                k++;
                ans++;
            }
        }else
            k++;
        cout<<ans<<" ";
    }
    cout<<endl;
}
