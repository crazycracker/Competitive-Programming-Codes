#include <bits/stdc++.h>

using namespace std;

int counts[100010];

int main(){
    int n,m;
    cin>>n>>m;

    long long int sum = n*(n+1)/2,x,preSum = 0;

    string str="";

    for(int i = 0; i < m; i++){
        cin>>x;
        if(counts[x] == 0){
            preSum += x;
            counts[x] = 1;
        }else{
            counts[x]++;
        }
        if(preSum == sum){
            preSum = 0;
            for(int k = 1; k <= n; k++){
                counts[k]--;
                if(counts[k] > 0)
                    preSum += k;
            }
            str += '1';
        }else{
            str += '0';
        }
    }
    cout<<str<<endl;
}
