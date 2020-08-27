#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c;

        if(((a+b)/c) % c == 0 ){
            cout<<"CHEF"<<endl;
        }else{
            cout<<"COOK"<<endl;
        }
    }
}
