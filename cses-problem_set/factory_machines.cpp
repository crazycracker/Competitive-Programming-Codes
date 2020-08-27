#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll getAnswer(vector<ll> arr, ll t, ll n,ll maxValue,bool flag){
    if(n == 1){
        return t * arr[0];
    }else if(flag){
        if(t % n != 0)
            return (t/n + 1) * arr[0];
        return (t/n) * arr[0];
    }
    ll low = 1, high = maxValue, mid,ans = 0,output;

    while(low <= high){
        mid = (low + high)/2;
        //cout<<mid<<'\n';
        output = 0;
        for(ll i: arr){
            output += mid/i;
        }
        if(output >= t){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    ll n,t;
    cin>>n>>t;

    ll maxValue = -1;
    vector<ll> arr;

    set<ll> sett;

    for(ll i = 0; i < n; i++){
        ll x;
        cin>>x;
        arr.push_back(x);
        sett.insert(x);
        maxValue += arr[i];
    }
    bool flag = false;

    if(sett.size() == 1)
        flag = true;
    cout<<getAnswer(arr, t, n, maxValue,flag);
    return 0;
}
