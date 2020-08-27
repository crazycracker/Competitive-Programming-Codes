#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;

    int val = (a + b - c);

    if(val != n)
        cout<<(n - val)<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
