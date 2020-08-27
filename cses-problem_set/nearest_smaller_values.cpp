#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n],index[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        index[i] = i - 1;
        while(~index[i] && arr[index[i]] >= arr[i])
            index[i] = index[index[i]];
        cout<<index[i] + 1<<' ';
    }
}
