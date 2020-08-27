#include <bits/stdc++.h>

using namespace std;

int a[200002];
int main(){
    int x, n;
    set <int> s;
    map <int,int> mp;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    mp[x] = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        auto it = s.lower_bound(a[i]);
        int r = *it;
        --it;
        int l = *it;
        --mp[r - l];
        if(!mp[r-l]) mp.erase(r-l);
        ++mp[r - a[i]];
        ++mp[a[i] - l];
        s.insert(a[i]);
        cout << ((--mp.end())->first) << ' ';
    }
}
