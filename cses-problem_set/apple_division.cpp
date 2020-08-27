#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calculate(ll arr[], ll n){
    ll sum = 0;

    for(ll i = 0; i < n; i++)
        sum += arr[i];
    bool dp[n+1][sum+1];
    memset(dp, true, sizeof(dp));
    for(ll i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    for(ll i = 1; i <= sum; i++)
        dp[0][i] = false;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            //cout<<"hello";
            if(arr[i-1] <= j){
                dp[i][j] |= dp[i-1][j - arr[i-1]];
            }
        }
    }
     ll diff = INT_MAX;

    for (ll j=sum/2; j>=0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
// Function to find the minimum sum
ll findMinRec(ll arr[], ll i, ll sumCalculated, ll sumTotal)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i==0)
        return abs((sumTotal-sumCalculated) - sumCalculated);


    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal),
               findMinRec(arr, i-1, sumCalculated, sumTotal));
}

// Returns minimum possible difference between sums
// of two subsets
ll findMin(ll arr[], ll n)
{
    // Compute total sum of elements
    ll sumTotal = 0;
    for (ll i=0; i<n; i++)
        sumTotal += arr[i];

    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal);
}
int main(){
    ll n;
    cin>>n;

    ll arr[n];

    for(ll i = 0; i < n; i++)
        cin>>arr[i];

    cout<<findMin(arr, n)<<'\n';
    return 0;
}
