#include <bits/stdc++.h>

using namespace std;

int sumPrime(int n) {
    int sum = 0;
    // find all powers of 2
    if(n%2 ==0){
        sum += 2;
        while (n%2 == 0) {
            n /= 2;
        }
    }

    // checking for factors up to sqrt(n) is sufficient
    for (int i = 3; i <= sqrt(n); i += 2) {
        // find all powers of i
        if(n%i == 0){
            sum += i;
            while (n%i == 0) {
                n /= i;
            }
        }
    }

    // n is prime at this point
    if (n > 2) {
        sum += n;
    }
    return sum;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int l,r;
        cin>>l>>r;

        long long int sum = 0;

        for(int i = l; i <= r; i++){
            sum += sumPrime(i);
            sum %= (1000000007);
        }
        cout<<sum<<endl;
    }
}
