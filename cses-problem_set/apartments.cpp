#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

lli des[200005],apar[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli n,m,k;
    cin>>n>>m>>k;

    for(int i = 0; i < n; i++)
        cin>>des[i];
    for(int i = 0; i < m; i++)
        cin>>apar[i];

    sort(des, des+n);
    sort(apar, apar+m);

    int ans = 0;

    for(int i = 0, j = 0; i < n; i++){
        while(j < m && apar[j] < des[i] - k)
            ++j;
        if(j < m && apar[j] <= des[i] + k)
            ++ans,++j;
    }
    cout<<ans<<'\n';
    return 0;
}

