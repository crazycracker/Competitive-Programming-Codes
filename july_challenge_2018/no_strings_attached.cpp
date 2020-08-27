#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;

        bool flag = true;

        for(int i = 0; i < str.length() - 1; i++){
            if(str[i] < str[i+1]){
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<"0"<<endl;
        }else{

        }
    }
}
