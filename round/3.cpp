#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string ss;
    cin>>ss;

    string st = "BGR";
    string str[9];
    vector<string> s;

    do{
        s.push_back(st);
    }while(next_permutation(st.begin(), st.end()));

    for(int i = 0; i < s.size(); i++){
        str[i] = "";
        for(int j = 0; j < n; j++){
            str[i] += (s[i][j%3]);
        }
    }

    int minCount = INT_MAX;
    string ans;
    for(int i = 0; i < s.size(); i++){
        int coun = 0;
        string temp = ss;
        for(int j = 0; j < n; j++){
            if(temp[j] != str[i][j]){
                temp[j] = str[i][j];
                coun++;
            }
        }
        if(minCount > coun){
            minCount = coun;
            ans = temp;
        }
    }

    cout<<minCount<<endl;
    cout<<ans<<endl;
}
