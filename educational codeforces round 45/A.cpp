#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,a,b;
    cin>>n>>m>>a>>b;

    if(n%m == 0){
        cout<<"0"<<endl;
    }else{
        long long int val1, val2;
        val1 = floor(n/m);
        val2 = ceil(n/m);
        if(val1 == val2){
            val2 = val1 + 1;
        }
        //cout<<val1<<' '<<val2<<endl;
        val1 = abs(m*val1 - n);
        val2 = abs(m*val2 - n);
        //cout<<val1<<' '<<val2<<endl;
        cout<<min(a*val2, b*val1)<<endl;
    }
    return 0;
}

