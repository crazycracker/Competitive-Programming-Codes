#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int k = 1; k <= t; k++){
        string x;
        cin>>x;

        string num1,num2;
        int len = x.length();

        for(int i = 0; i < len; i++){
            int dig1, dig2, val;
            val = x[i] - '0';
            if(val <= 3){
                num1 += (val + '0');
                num2 += '0';
            }else{
                dig1 = val/2;
                dig2 = (val % 2)?val/2 + 1:val/2;

                if(dig1 == 4){
                    dig1--;
                    dig2++;
                }else if(dig2 == 4){
                    dig1--;
                    dig2++;
                }

                num1 += (dig1 + '0');
                num2 += (dig2 + '0');
            }
        }
        int l = 0;

        while(l < num2.length() && num2[l] == '0'){
            l++;
        }
        cout<<"Case #"<<k<<":"<<" "<<num1<<" "<<num2.substr(l)<<endl;
    }
    return 0;
}
