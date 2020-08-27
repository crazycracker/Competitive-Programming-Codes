#include <bits/stdc++.h>

using namespace std;

map< pair<int,int> , bool> m;

int main(){
    int n,counts = 0;
    cin>>n;

    for(int i = 0; i < 10;i++){
        int in;
        cin>>in;

        for(int j = 1; j <= 9; j++){
                int x;
                cin>>x;
                if(!m[{in,x}] && !m[{x,in}]){
                    m[{in,x}] = m[{x,in}] = true;
                    counts++;
                }
        }
    }

    cout<<((n-1)*(n))/2 - counts<<'\n';
    return 0;
}
