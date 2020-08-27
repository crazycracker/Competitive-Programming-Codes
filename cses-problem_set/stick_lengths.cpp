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

    lli ans = 0;

    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);

    lli x = arr[n/2];

    for(int i = 0; i < n; i++)
        ans += abs(arr[i] - x);
    cout<<ans<<'\n';
    return 0;
}

