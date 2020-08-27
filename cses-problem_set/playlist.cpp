
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

    int ans = 0;
    map<int,int> mapp;

    for(int i = 0, j = 0;i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0,j = 0;i < n; i++){
        while(j < n && mapp[arr[j]] < 1){
            mapp[arr[j]]++;
            j++;
        }
        ans = max(j - i, ans);
        mapp[arr[i]]--;
    }
    cout<<ans<<'\n';
    return 0;
}

