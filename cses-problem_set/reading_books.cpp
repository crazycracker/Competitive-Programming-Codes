#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

const int maxn = 2e5;

lli a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    lli s = 0;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        s += a[i];
    }
    sort(a, a+n);
    cout<<max(s, 2 * a[n-1]);
    return 0;
}
