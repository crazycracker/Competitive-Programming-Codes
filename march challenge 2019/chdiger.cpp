#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2){
    if(s1.length() > s2.length())
        return false;
    if(s1.length() < s2.length())
        return true;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == s2[i])
            continue;
        if((s1[i]-'0') < (s2[i]-'0'))
            return true;
        else
            return false;
    }

    return false;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        char c;
        cin>>c;

        string temp = c + s.substr(1), temp2 = s.substr(0,s.length()-1) + c,temp3 = s.substr(1) + c, temp4 = c + s.substr(0,s.length()-1);

        if(compare(temp,s)){
            s = temp;
        }
        if(compare(temp2,s)){
            s = temp2;
        }
        if(compare(temp3,s)){
            s = temp3;
        }
        if(compare(temp4,s)){
            s = temp4;
        }
        cout<<s<<endl;
    }

    return 0;
}
