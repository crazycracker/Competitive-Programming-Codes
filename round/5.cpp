#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x,y;
    cin>>n>>m;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    while(m--){
        cin>>x>>y;
        for(int i = x-1; i < y; i++)
            arr[i]--;
    }

    for(int i = 1; i < n; i++)
        arr[i] += arr[i-1];

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
