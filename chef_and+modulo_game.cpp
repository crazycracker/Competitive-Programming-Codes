#include <bits/stdc++.h>

using namespace std;

struct node{
    int i,j,k;
};
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,p;
        cin>>n>>p;
        map<int,struct node> mapp;
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <=p; j++){
                for(int k = 1; k <= p; k++){
                    int val = (((n % i)%j)%k)%n;
                    struct node N;
                    N.i = i;
                    N.j = j;
                    N.k = k;
                    mapp[val].insert(N);
                }
            }
        }

        int maxi = INT_MIN;

        map<int, vector<struct node> > ::iterator *it;
        vector<struct node> vec;

        for(it = mapp.begin(); it != mapp.end(); it++){
            if(it->first > maxi){
                maxi = it->first;
                vec = it->second;
            }
        }

        cout<<vec.size()<<endl;
    }
}
