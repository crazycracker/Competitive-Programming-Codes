#include <bits/stdc++.h>

using namespace std;

unsigned int intToGray(int num){
    return (num ^ (num >> 1));
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cout<<intToGray(intToGray(intToGray(intToGray(i))))<<" ";
        }
        cout<<endl;
    }
}
