#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int k = 1; k <= t; k++){
        unsigned long long int n,l;
        cin>>n>>l;

        long long int x;
        vector<long long int> vec;

        for(int i = 0; i < l; i++){
            cin>>x;
            vec.push_back(x);
        }
        vector<long long int> gcds,primes;

        for(int i = 1; i < l; i++){
            gcds.push_back(__gcd(vec[i],vec[i-1]));
        }
        primes.push_back(vec[0]/gcds[0]);

        for(int i = 0; i < l; i++){
            primes.push_back(vec[i]/primes[i]);
        }
        gcds.clear();
        gcds = primes;

        sort(gcds.begin(), gcds.end());
        map<long long int,char> mapp;
        int l1 = 0;
        for(int i = 0; i < gcds.size(); i++){
            if(mapp.find(gcds[i]) == mapp.end()){
                mapp[gcds[i]] = 65 + l1;
                l1++;
            }
        }
        cout<<"Case #"<<k<<":"<<" ";
        for(int i = 0; i < primes.size(); i++)
            cout<<mapp[primes[i]];
        cout<<endl;
    }
    return 0;
}


