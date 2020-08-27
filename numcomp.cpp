#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        long long int a,b,n;

        scanf("%lld%lld%lld", &a, &b, &n);

        if(a == b){ 
            cout<<"0"<<endl;
        }else{
            if(n % 2 == 1){
                if(a < b){
                    cout<<"2"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }else{
                a = abs(a);
                b = abs(b);
                if(a < b){
                    cout<<"2"<<endl;
                }else if(a > b){
                    cout<<"1"<<endl;
                }else{
                    cout<<"0"<<endl;
                }
            }
        }
    }
    return 0;
}
