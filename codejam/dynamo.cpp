#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    unsigned long long int val,a,b,c,d,e;

    while(t--){
        int n;
        cin>>n;

        cin>>a;

        val = pow(10,n) - 1;

        cout<<val<<'\n';

        cin>>b;

        val -= (a + b);

        cout<<val<<'\n';

        cin>>c;

        val -= c;

        cout<<val<<'\n';

        cin>>d;


        if(d == -1){
            break;
        }else{
            cout<<endl;
            //flush(stdin);
        }
    }
    return 0;
}
