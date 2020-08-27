#include <bits/stdc++.h>

#define lli long long int
#define li long int
#define ld long double
using namespace std;

lli arr[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,ans = 0;
    cin>>n>>x;

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    sort(arr, arr+n);

    for(int i = 0, j = n - 1; i < j ; ){
        while(i < j && arr[i] + arr[j] > x)
            --j;
        if(i >= j)
            break;
        ans++;
        i++,j--;
    }
    cout<<n - ans<<'\n';
    return 0;
}
