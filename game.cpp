#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    printf("Enter No of players\n");
    cin>>n;
    printf("Enter No of games\n");
    cin>>m;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
                for(int k = 0; k < m; k++)
                    cout<<"player "<<i<<" is playing game "<<k+1<<" "<<"with player "<<j<<endl;
        }
    }
}
