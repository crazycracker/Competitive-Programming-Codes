#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    bool flag = false;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(x)
            flag = true;
    }

    if(flag)
        cout<<"HARD"<<endl;
    else
        cout<<"EASY"<<endl;
}
