#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r+",stdin);
    int n,m;
    cin>>n>>m;

    long long int x;
    vector<long long int> a,b;
    for(int i = 0; i < n; i++){
        cin>>x;
        a.push_back(x);
    }
    
    for(int i = 0; i < m; i++){
        cin>>x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long int f,g;
    long long int ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i++){
        f = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        g = upper_bound(b.begin(),b.end(),a[i]) - b.begin();    
        ans1 += ((f)*(m-g));
    }
    for(int i = 0; i < m; i++){
        f = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        g = upper_bound(a.begin(),a.end(),b[i]) - a.begin();    
        ans2 += ((f)*(n-g));
    }

    if(ans1 > ans2){
        cout<<"Monk "<<(ans1 - ans2)<<endl;
    }else if(ans2 > ans1){
        cout<<"!Monk "<<abs(ans1 - ans2)<<endl;
    }else{
        cout<<"Tie"<<endl;
    }

    return 0;
}