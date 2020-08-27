#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;

    sort(str.begin(),str.end());
    int ch[26],ones = 0;
    memset(ch, 0, sizeof(ch));

    char one;

    for(int i = 0; i < str.length(); i++){
        ch[str[i] - 'A']++;
    }
    string finalString = "";

    for(int i = 0; i < 26; i++){
        if(ch[i] > 0 && ch[i] % 2 == 0){
            char c = ('A' + i);

            int cnt = ch[i]/2;

            while(cnt){
                finalString += c;
                cnt--;
            }
        }
        if(ch[i] % 2 == 1){
            ones++;
            one = 'A' + i;
        }
    }

    string temp = finalString;

    if(ones == 1){
        int cnt = ch[one-'A'];
        while(cnt){
            finalString += one;
            cnt--;
        }
    }else if(ones > 1){
        cout<<"NO SOLUTION"<<'\n';
        return 0;
    }

    for(int i = temp.length()-1; i >= 0; i--){
        finalString += temp[i];
    }

    if(finalString.length() != str.length()){
        cout<<"NO SOLUTION"<<'\n';
        return 0;
    }

    cout<<finalString;

    return 0;
}
