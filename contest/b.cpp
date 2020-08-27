#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> odd,even;
        vector<pair<int,int>> ans;

        for(int i = 1; i <= 2*n; i++){
            int x;
            cin>>x;
            if(x % 2)
                odd.push_back(i);
            else
                even.push_back(i);
        }

        for(int i = 0; i+1 < odd.size(); i+=2){
            ans.push_back({odd[i],odd[i+1]});
        }
        for(int i = 0; i+1 < even.size(); i+=2){
            ans.push_back({even[i],even[i+1]});
        }

        for(int i = 0; i < n-1; i++)
            cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    }
    return 0;
}
