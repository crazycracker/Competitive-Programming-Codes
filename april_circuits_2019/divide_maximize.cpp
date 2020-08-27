#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    scanf("%d%d", &n, &k);

    int x;
    vector< pair<int,int> > vec;

    for(int i = 0; i < 2*n; i++){
        cin>>x;
        vec.push_back(make_pair(x,i+1));
    }

    for(int i = 0; i < 2*n-1; i+=2){
        if(vec[i].first > vec[i+1].first){
            pair<int,int> temp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = temp;
        }
    }

    for(int i = 0; i < 2*n; i++){
        if(i%2 == 0)
            cout<<vec[i].second<<endl;
    }
    for(int i = 0; i < 2*n; i++){
        if(i%2 == 1)
            cout<<vec[i].second<<endl;
    }

    return 0;
}
