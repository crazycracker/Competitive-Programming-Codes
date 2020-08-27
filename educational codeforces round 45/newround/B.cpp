#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,sum=0;
    cin>>n;

    vector<int> vec;

    for(int i = 0; i < n; i++){
        cin>>x;
        sum += x;
        vec.push_back(5-x);
    }
    sort(vec.begin(), vec.end());
    float val = 4.5 * n - floor(4.5 * n);
    if(val == 0.5){
        val = floor(4.5 * n) + 1;
    }else{
        val = floor(4.5 * n);
    }
    if(val <= sum){
        cout<<"0"<<endl;
        return 0;
    }
    val = val - sum;
    int cnt = 0;

    for(int i = n-1; i >= 0; i--){
        cnt += vec[i];
        if(cnt >= val){
            cout<<(n - i)<<endl;
            break;
        }
    }
    return 0;
}
