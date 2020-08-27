#include <bits/stdc++.h>

using namespace std;

string to_strings(int cnt){
    string str;

    while(cnt){
        str += (cnt%10 + '0');
        cnt /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main(){
    int t;
    cin>>t;

    int a[26] = {0};

    a['f'-'a'] = a['r'-'a'] = a['i'-'a'] = a['e'-'a'] = a['z'-'a'] = a['a'-'a'] = 1;

    while(t--){
        string str,ans;
        cin>>str;

        int i = 0,len = str.length();

        while(i < len){
            int cnt = 0;
            if(a[str[i] - 'a']){
                while(i < len && a[str[i]-'a']){
                    cnt++;
                    i++;
                }
            }else{
                while(i < len && a[str[i]-'a'] != 1){
                    cnt++;
                    i++;
                }
            }
            ans += (to_strings(cnt));
        }

        cout<<ans<<endl;
    }
}
