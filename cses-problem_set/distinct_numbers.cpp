#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    set<int> ss;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        ss.insert(x);
    }
    cout<<ss.size()<<'\n';
    return 0;
}
