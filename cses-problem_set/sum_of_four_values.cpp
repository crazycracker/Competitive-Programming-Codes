#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

const int maxn = 1e3;

lli n, x;
pair<lli,lli> a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;

    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a, a+n);

    vector<lli> index;

    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int i1 = i + 1; i1 < n; i1++){
            lli x2 = x - a[i].first - a[i1].first;
            for(int j = i1 + 1, k = n - 1; j <= k; j++){
                while(j < k && a[j].first + a[k].first > x2)
                    k--;
                if(j < k && a[j].first + a[k].first == x2){
                    index.push_back(a[i].second);
                    index.push_back(a[i1].second);
                    index.push_back(a[j].second);
                    index.push_back(a[k].second);
                    flag = true;
                    break;
                }
            }

            if(flag)
                break;
        }

        if(flag)
            break;
    }

    if(!flag)
        cout<<"IMPOSSIBLE";
    else
    {
        sort(index.begin(), index.end());

        for(int i = 0; i < (int)index.size(); i++)
            cout<<index[i] + 1<<' ';
    }
    return 0;
}
