#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n,m,k;
    cin>>n>>m>>k;

    int alloc[m], seating[n];
    memset(alloc,0,sizeof(alloc));
    
    for(int i = 0; i < n;i++){
        cin>>seating[i];
    }
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(alloc[seating[i]-1] < k){
            alloc[seating[i]-1]++;
        }else{
            ans++;
            int j = i,cnt = 0;
            while(cnt < n && alloc[seating[j%m]-1] == k){
                j++;
                cnt++;
            }

            if(cnt < n){
                alloc[seating[j%m]-1]++;
            }            
        }
    }
    cout<<ans<<endl;
}