#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> vec;
    vec.resize(n);
    int index1,index2,index3,index4;

    for(int i = 0; i < n; i++){
        cin>>vec[i];
        if(vec[i] == n){
            index1 = i;
        }
        if(vec[i] == n-1){
            index2 = i;
        }
        if(vec[i] == 1){
            index3 = i;
        }
        if(vec[i] == 2){
            index4 = i;
        }
    }
    vec[index1] = 1;
    vec[index2] = 2;
    vec[index3] = n;
    vec[index4] = n-1;

    for(int i = 0; i < n; i++){
        cout<<vec[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
