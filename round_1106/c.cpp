#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    sort(arr,arr+n);

    long long int sum = 0;

    for(int i = 0,j = n-1; i < j; i++,j--){
        int val = arr[i] + arr[j];
        sum += (val * val);
    }

    cout<<sum<<endl;
}
