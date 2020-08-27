#include <bits/stdc++.h>

using namespace std;

int main(){
    int t ;
    cin>>t;

    while(t--){
        int n,m,x,k;
        string str;

        cin>>n>>m>>x>>k;
        cin>>str;

        if(x == 0 || m == 0){
            cout<<"no"<<endl;
        }else{
            int even,odd,geven,godd;
            even = odd = 0;
            geven = (m/2);

            if(n%2 == 1)
                godd = geven + 1;
            else
                godd = geven;

            for(int i = 0;i < str.length(); i++){
                if(str[i] == 'E')
                    even++;
                else
                    odd++;
            }
        }
    }
}
