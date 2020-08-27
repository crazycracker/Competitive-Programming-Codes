#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

int dp[102][2];
int n, k ,d;

int func(int sum, int chk){
    if(sum > n) return 0;
    if(sum == n){
        if(chk)
            return 1;
        else
            return 0;
    }

    if(dp[sum][chk] != -1)
        return dp[sum][chk];
    int ans = 0;

    for(int i = 1; i <= k; i++){
        if(i >= d){
            ans = (ans + func(sum+i,1))%M;
        }else{
            ans = (ans + func(sum+i,chk))%M;
        }
    }
    dp[sum][chk] = ans;
    return dp[sum][chk];
}
int main(){
    scanf("%d%d%d", &n, &k, &d);
    memset(dp,-1,sizeof(dp));
    cout<<func(0,0)<<endl;
}
