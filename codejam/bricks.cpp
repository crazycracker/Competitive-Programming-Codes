#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a[4];

        for(int i = 0; i < 4; i++)
            cin>>a[i];

        if(a[0] >= (a[1] + a[2] + a[3])){
            cout<<1<<'\n';
        }else{
            if(a[0] >= (a[1] + a[2]) || a[0] >= (a[2] + a[3])){
                cout<<2<<'\n';
            }else{
                cout<<3<<'\n';
            }
        }
    }
    return 0;
}
