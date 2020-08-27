#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    bool flag = true;

    for(int i = 1; i < n; i++){
        if(s[i] == s[0]){
            continue;
        }else{
            cout<<"YES"<<endl;
            cout<<s[0]<<s[i]<<endl;
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"NO"<<endl;
    }
}
