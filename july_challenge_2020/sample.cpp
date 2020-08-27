#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> vec(n);
    int counts = 0;

    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++)
        cin>>vec[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(vec[j] != vec[i] && vec[i] != vec[k]&& vec[j] != vec[k] && vec[i] + vec[j] > vec[k] && vec[j] + vec[k] > vec[i] && vec[i] + vec[k] > vec[j]){
                    cout<<i+1 <<' '<<j+1<<' '<<k+1<<'\n';
                    counts++;
                }
            }
        }
    }
    cout<<counts;
    return 0;
}
