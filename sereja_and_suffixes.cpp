#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,num;
    cin>>n>>m;

    bool arr[100010];
    memset(arr,false,sizeof(arr));

    int cnt[n+1],b[n];
    memset(cnt,0,sizeof(cnt));

    cnt[n] = 0;
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    for(int i = n-1; i >= 0; i--){
        num = b[i];
        if(arr[num] == false){
            cnt[i] = cnt[i+1] + 1;
            arr[num] = true;
        }else{
            cnt[i] = cnt[i+1];
        }
    }
    for(int i = 0; i < m; i++){
        cin>>num;
        cout<<cnt[num-1]<<endl;
    }
}
