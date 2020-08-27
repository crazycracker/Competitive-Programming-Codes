// CPP program to find max xor sum
// of 1 to n using atmost k numbers
#include <bits/stdc++.h>
using namespace std;

// To return max xor sum of 1 to n
// using at most k numbers
void maxXorSum(int n, int k)
{
    // If k is 1 then maximum
    // possible sum is n
    if (k == 1)
        cout<<n<<endl;

    // Finding number greater than
    // or equal to n with most significant
    // bit same as n. For example, if n is
    // 4, result is 7. If n is 5 or 6, result
    // is 7
    int res = 1;
    int cnt = 0;
    while (res <= n){
        cout<<res<<endl;
        res <<= 1;
        cnt++;
    }
    res = res - 1;
    while(res <= n && cnt < k){
        cout<<res<<endl;
        cnt++;
    }
}

// Driver program
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        maxXorSum(k,n);
    }
    return 0;
}
