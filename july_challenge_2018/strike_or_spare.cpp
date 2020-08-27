#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n == 1){
            cout<<"1 1"<<endl;
        }else{
            int den = n/2;

            cout<<"1 1";
            for(int i = 0; i < den; i++){
                cout<<"0";
            }
            cout<<endl;
        }
    }
    return 0;
}
