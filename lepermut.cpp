#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n;

        vector<int> vec;

        for(int i = 0; i < n; i++){
            cin>>x;
            vec.push_back(x);
        }

        int localInversions, inversions;
        localInversions = inversions = 0;

        for(int i = 0; i < n-1; i++){
            if(vec[i] < vec[i+1]){
                localInversions++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(vec[i] > vec[j])
                    inversions++;
            }
        }

        if(localInversions == inversions)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
