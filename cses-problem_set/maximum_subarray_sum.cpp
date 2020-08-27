#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

const int maxx = 200005;

lli arr[maxx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    lli curr_sum,max_so_far;
    curr_sum = max_so_far = INT_MIN;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        curr_sum = max(arr[i],curr_sum + arr[i]);
        max_so_far = max(max_so_far, curr_sum);
    }
    cout<<max_so_far;
    return 0;
}

