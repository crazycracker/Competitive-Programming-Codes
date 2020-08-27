#include <bits/stdc++.h>

using namespace std;

void changeTheSigns(long long int arr[], int n, map<int,bool> m){
    long long int temp;
    long long int prefixSum[n+2];

    prefixSum[0] = prefixSum[n+1] = 0;

    if(m[1])
        prefixSum[1] = -arr[1];
    else
        prefixSum[1] = arr[1];

    for(int i = 2; i <= n; i++){
        if(m[i])
            prefixSum[i] = prefixSum[i-1] - arr[i];
        else
            prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    for(int i = 3; i <= n; i++){
        for(int j = i; j <= n; j++){
            temp = prefixSum[j] - prefixSum[j-i];
            //cout<<j-i<<" "<<j<<" "<<"Sum = "<<temp<<endl;
            if(temp > 0)
                continue;
            else{
                long long int index = -1, temp1 = INT_MIN;
                for(int k = j-i+1; k <= j; k++){
                    if(m[k] && arr[k] > temp1 && arr[k] >= (1-temp))
                    {
                        temp1 = arr[k];
                        index = k;
                    }
                }

                if(index != -1){
                    m[index] = false;
                    //cout<<index<<endl;
                    for(int k = index; k <= n; k++){
                        prefixSum[k] += (2*arr[index]);
                    }
                }
            }
        }
    }

    //unsigned long long int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(m[i]){
            //sum -= arr[i];
            //arr[i] = -arr[i];
            cout<<"-"<<arr[i]<<" ";
        }else{
            //sum += arr[i];
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
    //cout<<sum<<" "<<prefixSum[n]<<endl;
    return;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long int arr[n+2],sum = 0, temp = 0;

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

        changeTheSigns(arr,n,m);
    }
}
