#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n;
        cin>>m;

        n = min(n,m);

        if(n%2)
            cout<<"Sherlock"<<endl;
        else
            cout<<"Watson"<<endl;
    }
}
