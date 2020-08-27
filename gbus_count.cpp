#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,k=1;
    cin>>t;

    while(t--){
        int n,u,v;
        cin>>n;
        vector<int> arr(5001, 0);

        for(int i = 0; i < n; i++){
            cin>>u>>v;
            for(int j = u; j <= v; j++){
                arr[j]++;
            }
        }

        int p,x;
        cin>>p;
        vector<int> q;

        while(p--){
            cin>>x;
            q.push_back(x);
        }

        printf("Case #%d:", k);
        for(int i = 0; i < q.size(); i++){
            cout<<" "<<arr[q[i]];
        }
        cout<<endl;
        k++;
    }
}
