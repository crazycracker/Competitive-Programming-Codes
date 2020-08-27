#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> vec;

    for(int i = 0;i < n; i++){
        int a;
        cin>>a;

        int p = upper_bound(vec.begin(), vec.end(), a) - vec.begin();

        if(p < vec.size()){
            vec[p] = a;
        }else{
            vec.push_back(a);
        }
    }
    cout<<vec.size();
    return 0;
}
