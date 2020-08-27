#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string str;
    cin>>str;

    bool flag = false;

    for(int i = 0,j = str.length() - 1;i < j;){
        if(str[i] == str[j]){
            j--;
        }else if(str[i] > str[j]){
            flag = true;
            cout<<"YES"<<endl;
            cout<<i<<" "<<j<<endl;
            break;
        }else{
            j--;
        }
    }

    if(!flag)
        cout<<"NO"<<endl;
}
