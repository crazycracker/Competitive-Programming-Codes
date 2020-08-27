#include <bits/stdc++.h>

using namespace std;

bool primes[2000001];

void initialize(){
    memset(primes, true, sizeof(primes));

    primes[0] = primes[1] = false;

    long long int ans = 2;

    for(int i = 4;i < 2000001; i+=2)
        primes[i] = false;
    for(int i = 3; i < 2000001; i += 2){
        if(primes[i]){
            ans += i;
            for(int j = 2*i; j < 2000001; j += i)
                primes[j] = false;
        }
    }
    cout<<ans<<endl;
}

unsigned long long int factorial(int a,int b){
    unsigned long long int ans = 1;

    for(int i = a; i <= b; i++)
        ans *= i;
    return ans;
}
int main(){
    //initialize();
    cout<<factorial(21,40)<<endl;
    cout<<factorial(1,20)<<endl;
    cout<<factorial(21,40)/(factorial(1,20))<<endl;
}
