#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k,x,ans=0;
        cin>>n>>k;
        vector<int> vec1,vec2,pos;
        bool pre[n+1];
        memset(pre,false,sizeof(pre));

        for(int i = 0; i < n; i++){
            cin>>x;
            vec1.push_back(x);
            pre[x] = true;
            if(x == 0)
                pos.push_back(i);
        }
        for(int i = 1; i <= n; i++){
            if(!pre[i]){
                vec2.push_back(i);
            }
        }
        do{
            int cnt = 0,j = 0;
            for(int i = 0; i < pos.size(); i++){
                vec1[pos[i]] = vec2[j++];
            }

            for(int i = vec1.size()-1; i > 0; i--){
                //cout<<vec1[i]<<' '<<vec1[i-1]<<endl;
                if(vec1[i] > vec1[i-1]){
                    cnt++;
                }
            }

            if(cnt == k){
                ans++;
            }
            for(int i = 0; i < pos.size(); i++){
                vec1[pos[i]] = 0;
            }
        }while(next_permutation(vec2.begin(),vec2.end()));

        cout<<ans<<endl;
    }
    return 0;
}
