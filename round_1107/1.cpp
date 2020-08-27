#include <bits/stdc++.h>

using namespace std;

int stringToInteger(string str, int start, int endd){
    int value = 0, p = 0;

    for(int j = endd; j >= start; j--){
        value += ((str[j]-48)*pow(10,p));
        p++;
    }

    return value;
}
int main(){
    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;

        string str;
        cin>>str;

        string str1, str2;

        str1 = str[0];

        str2 = str.substr(1,str.length());

        if(str1 != str2){
            cout<<"YES"<<endl;
            cout<<"2"<<endl;
            cout<<str1<<" "<<str2<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
