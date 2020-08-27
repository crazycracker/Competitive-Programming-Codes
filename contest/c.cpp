#include <bits/stdc++.h>

using namespace std;

const int N = 50000;

int check_prime(int n){
    for(int i = 2; i < min(N,n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n == 1){
            cout<<"FastestFinger"<<'\n';
        }else if(n == 2){
            cout<<"Ashishgup"<<'\n';
        }else if(n % 2){
            cout<<"Ashishgup"<<'\n';
        }else{

            if((n & (n - 1)) == 0){
                cout<<"FastestFinger"<<'\n';
            }else if(n % 4 != 0 && check_prime(n/2)){
                cout<<"FastestFinger"<<'\n';
            }else{
                cout<<"Ashishgup"<<'\n';
            }
        }
    }
    return 0;
}
