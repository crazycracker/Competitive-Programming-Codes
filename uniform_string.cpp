#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    char ch[26];
    ch[0] = 'a';

    for(int i = 1; i < 26; i++)
        ch[i] = ch[i-1] + 1;

    while(t--){
        int n,k;
        cin>>n>>k;

        int i = 0;
        string str;

        while(i < n){
            for(int j = 0; j < k && i < n; j++,i++)
                str += ch[j];
        }
        cout<<str<<endl;
    }
}
