#include <bits/stdc++.h>

using namespace std;

string prefix_string(string str1, string str2){
    string str;
    int i,j,len1,len2;
    i = j = 0;
    len1 = str1.length();
    len2 = str2.length();

    while(i < len1 && j < len2 && str1[i] == str2[j]) i++,j++;
    return str1.substr(0,i);
}

int main(){
    int n;
    cin>>n;

    vector<string> vec;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        vec.push_back(str);
    }
    vector<string> prefix;
    if(n > 1){
        prefix.push_back(prefix_string(vec[0],vec[1]));

        for(int i = 2;i < n; i++){
            prefix.push_back(prefix_string(prefix[i-1],vec[i]));
        }
    }else{
        prefix.push_back(vec[0]);
    }

    int q;
    cin>>q;

    while(q--){
        int n;
        string str;
        cin>>n>>str;

    }
}
