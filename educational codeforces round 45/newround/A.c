#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;

    int val = (n - (a + b - c));

    if(val > 0)
        cout<<val<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
