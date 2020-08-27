#include <bits/stdc++.h>

using namespace std;

string calc(int a,int b){
    string no = "NO", yes = "YES";

    if(a ==0 || b == 0 || (a == 1 && b == 1) || (a == 2 && b == 2) || (a == b && a % 2 == 1))
        return no;
    if(__gcd(a, b) == 1 || __gcd(a, b) == 2)
        return yes;
    return no;
}
int main(){
    int t;
    cin>>t;

    while(t--){

        int a,b;
        cin>>a>>b;

        cout<<calc(a,b)<<'\n';
    }
    return 0;
}
