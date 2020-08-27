#include <bits/stdc++.h>

using namespace std;

const int MAX = 4*1e4 + 5;

bool prime[MAX];

void sieve(){
    memset(prime,true,sizeof(prime));

    prime[0] = prime[1] = false;

    for(int i = 2; i < MAX; i++){
        if(prime[i]){
            for(int j = i * 2; j < MAX; j++)
                prime[j] = false;
        }
    }
    return;
}

int main(){
    int t;
    cin>>t;

    sieve();

    while(t--){
        int n;
        cin>>n;

        if(prime[n]){
            cout<<"-1"<<endl;
        }else{
            vector<int> divisors;

            for(int i = 1; i <= sqrt(n); i++){
                if(n%i == 0){
                    if(n/i == i){
                        divisors.push_back(i);
                    }else{
                        divisors.push_back(i);
                        divisors.push_back(n/i);
                    }
                }
            }

            for(int i = 0; i < divisors.size(); i++){
                cout<<divisors[i]<<endl;
            }
        }
    }
}
