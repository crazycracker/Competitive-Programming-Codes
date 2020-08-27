#include <bits/stdc++.h>
#define ll long long int
#define ar array

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string str;
        cin>>str;

        int i = 0;

        while(i < n && str[i] == '0')
            i++;
        while(i < n && str[i] == '1'){
            i++;
        }

        if(i == n){
                cout<<str<<'\n';
        }
        else{
            i = 0;
            string ans = "";


            while(i < n && str[i] == '0'){
                i++;
                ans += '0';
            }
            ans += '0';
            i = n - 1;
            while(i >= 0 && str[i] == '1'){
                i--;
                ans += '1';
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
