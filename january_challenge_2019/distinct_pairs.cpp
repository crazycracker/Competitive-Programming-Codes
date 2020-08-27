#include <bits/stdc++.h>

using namespace std;

bool positive[1000000001];

int main(){
    int n,m;

    cin>>n>>m;

    long long int a[n], b[m], lowest;

    lowest = INT_MAX;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        lowest = min(a[i], lowest);
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
        lowest = min(b[i], lowest);
    }

    for(int i = 0; i < n; i++)
        a[i] -= lowest;
    for(int i = 0; i < m; i++)
        b[i] -= lowest;

    long long int counts = 0, k = n + m - 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            long long int val = a[i] + b[j];
            if(!positive[val]){
                positive[val] = true;
                if(counts < k){
                    counts++;
                    cout<<i<<" "<<j<<endl;
                }else{
                    break;
                }
            }
        }
        if(counts == k)
            break;
    }
    return 0;
}
