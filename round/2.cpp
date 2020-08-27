#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n;

    vector<int> vec;

    for(int i = 0; i < n; i++){
        cin>>x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    int value = vec[vec.size()-1],value2;
    bool present[10010];
    memset(present, false, sizeof(present));

    for(int i = 0; i < vec.size(); i++){
        if(value % vec[i] == 0 && !present[vec[i]]){
            present[vec[i]] = true;
            vec[i] = -1;
        }
    }

    for(int i = vec.size()-1; i >= 0; i--){
        if(vec[i] != -1)
        {
            value2 = vec[i];
            break;
        }
    }
    cout<<value<<" "<<value2<<endl;
}
