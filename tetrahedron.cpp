#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

int main(){
    long long arr[10000001] = {0,0,3,6};
    int n;
    cin>>n;
    for(int i = 4; i <=n; i++){
        arr[i] = (3*arr[i-2] + 2*arr[i-1])%M;
    }
    cout<<arr[n]<<endl;
    return 0;
}
