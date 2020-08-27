#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;

        int len = str.length();
        int cnt = 0;
        for(int i = 0; i <= len-4; i++){
            int ch[26] = {0};
            for(int j = i; j < i + 4 && j < len; j++){
                ch[str[j]-'a']++;
            }
            if(ch[2] != 0 && ch[7] != 0 && ch[4] != 0 && ch[5] != 0){
                cnt++;
            }
        }

        if(cnt > 0)
            cout<<"lovely "<<cnt<<endl;
        else
            cout<<"normal"<<endl;
    }
}
