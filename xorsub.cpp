#include <bits/stdc++.h>

using namespace std;

int dp[1024][1024];
int arr[1024];

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int ans = k;
        arr[0] = 0;

        for(int i = 1; i <= n; i++){
            cin>>arr[i];
        }
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 1024; j++){
                dp[i][j] = dp[i-1][j] | dp[i-1][j ^ arr[i]];
            }
        }
        for(int j = 0; j < 1024; j++){
            ans = max(ans, dp[n][j] * (j ^ k));
        }
        cout<<ans<<endl;
    }
}
