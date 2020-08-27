#include <bits/stdc++.h>

using namespace std;

int previousPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);
}

unsigned int nextPowerOf2(unsigned int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,n1,n2,n3,n4;
        cin>>n;

        n1 = nextPowerOf2(n);
        n2 = previousPowerof2(n);

        n3 = n - n2;
        if((n3 & (n3 - 1) == 0) && n3 != 0){
            cout<<"0"<<endl;
        }else if(n3 == 0){
            cout<<"1"<<endl;
        }else{
            int n5 = previousPowerof2(n3);
            int n6 = nextPowerOf2(n3);

            if(n - n2 == n6 - n3){
                n6 = nextPowerOf2(n3 + 1);
            }
            cout<<min(abs(n3-n5),abs(n6-n))<<endl;
        }
    }
}
