#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;

    int i = 0, n = str.length(), j = n-1;

    while(i < n && str[i] != '[')
        i++;
    while(i < n && str[i] != ':')
        i++;
    while(j >= 0 && str[j] != ']')
        j--;
    while(j >= 0 && str[j] != ':')
        j--;

    if(i < j){
        int cnt = 0;
        for(int k = i + 1; k < j; k++){
            cnt += ((str[i] == '|')? 1 : 0);
        }
    cout<<cnt+4<<endl;
    }else{
        cout<<"-1"<<endl;
    }
}
