#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll,ll> mp;
map<ll,ll>::iterator it;

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n,x,maxi = -1;
        cin>>n>>x;

        mp.clear();

        for(int i = 0; i < n; i++){
            ll temp;
            cin>>temp;
            mp[temp]++;
            maxi = max(temp,maxi);
        }
        if(maxi <= x){
            cout<<n<<'\n';
            continue;
        }
        ll temp = x,days = 0;

        while(temp <= maxi){
            it = mp.lower_bound(temp);
            //cout<<temp<<' '<<it->first<<'\n';
            if(temp >= it->first){
                days += it->second;
                temp = 2 * it->first;
                mp.erase(it->first);
            }else{
                temp += temp;
                temp = min(temp,it->first);
                days++;
            }
        }
        cout<<days+mp.size()<<'\n';
    }
}
