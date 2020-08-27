#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        unsigned long long int arr[n+2],sum = 0, temp = 0;

        arr[0] = arr[n+1] = INT_MAX;

        for(int i = 1; i <= n; i++){
            cin>>arr[i];
        }

        map<int,bool> m;

        for(int i = 1; i <= n; i++){
            if((arr[i] < arr[i-1]) && (arr[i] < arr[i+1])){
                m[i] = true;
            }else{
                m[i] = false;
            }
        }

        if(m[1])
            sum -= arr[1];

        for(int i = 2; i <= n; i++){
            temp = 0;
            if(m[i]){
                temp = sum - arr[i];
            }else{
                temp = sum + arr[i];
            }

            if(temp > 0){
                sum = temp;
            }else{
                sum += arr[i];
                m[i] = false;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(m[i])
                cout<<"-"<<arr[i]<<" ";
            else
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
