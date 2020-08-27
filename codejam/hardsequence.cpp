#include <bits/stdc++.h>

using namespace std;

int main(){
    const int MAX = 140;
    int a[MAX];
    memset(a,0,sizeof(a));

    for(int n = 0; n < MAX; n++){
        for(int m = n - 1;m >= 0; m--){
            if(a[m] == a[n]){
                a[n+1] = n - m;
                break;
            }
        }
    }
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int temp = a[n-1],cnt= 0;

        for(int i = 0; i < n; i++){
            if(a[i] == temp)
                cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
