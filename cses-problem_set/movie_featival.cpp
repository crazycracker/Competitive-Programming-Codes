#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

ar<int,2> a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i][1]>>a[i][0];
    }
    sort(a,a+n);
    int l = -1,ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i][1] >= l){
            ans++;
            l = a[i][0];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
