#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int k = 1; k <= t; k++){
        int n;
        cin>>n;

        string x;
        cin>>x;
        string ans;

        for(int i = 0; i < x.length(); i++){
            if(x[i] == 'E')
                ans += "S";
            else
                ans += "E";
        }
        cout<<"Case #"<<k<<":"<<" "<<ans<<endl;
    }
    return 0;
}

