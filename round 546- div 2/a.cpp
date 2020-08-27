#include <bits/stdc++.h>

using namespace std;

int arr[10010];

int main(){
    int n,k,l,r;
    cin>>n;

    k = 1;

    for(int i = 0; i < n; i++){
        cin>>l>>r;
        for(int j = l; j <= r; j++){
            arr[j] = k;
        }
        k++;
    }

    int x;
    cin>>x;

    cout<<(n - arr[x] + 1)<<endl;

    return 0;
}
