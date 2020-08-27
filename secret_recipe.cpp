#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        double x1,x2,x3,v1,v2;
        cin>>x1>>x2>>x3>>v1>>v2;

        x1 = (abs(x3-x1)/v1);
        x2 = (abs(x3-x2)/v2);

        if(x1 == x2)
            cout<<"Draw"<<endl;
        else if(x1 < x2)
            cout<<"Chef"<<endl;
        else
            cout<<"Kefa"<<endl;
    }
}
