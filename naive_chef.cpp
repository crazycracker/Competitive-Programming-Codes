#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,a,b;
        cin>>n>>a>>b;

        int arr[n],u;
        double presence[10005];
        memset(presence,0,sizeof(presence));
        for(int i = 0; i < n; i++)
        {
            cin>>u;
            presence[u]++;
        }

        printf("%.10f\n",(float)((presence[a]/n)*(presence[b]/n)));
    }
    return 0;
}
