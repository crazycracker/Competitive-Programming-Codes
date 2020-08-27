#include <bits/stdc++.h>
using namespace std;
string convertToString(int x){
    string str = "";

    while(x != 0){
        str +=((x%10)-'0');
        x = x/10;
    }
    cout<<str<<endl;
    string ans = "";
    for(int i = str.length()-1; i >= 0; i--)
        ans += str[i];
    return ans;
}
string solution(vector <int> array) {
    sort(array.begin(), array.end());
    int i = 0;
    string str;
    while(i < array.size()){
        str += convertToString(array[i]);
        int counts = 1;
        int k = i;
        while(i+1 < array.size() && array[i]+1 == array[i+1]){
            counts++;
            i++;
        }
        if(counts >= 3){
            str += "-";
            str += convertToString(array[i]);
        }else{
            i = k + 1;
        }
        if(i != array.size()-1)
            str += ",";
    }
    return str;
}

int main(){
    int n;
    cin>>n;

    vector<int> a;
    int u;

    for(int i = 0; i < n; i++){
        cin>>u;
        a.push_back(u);
    }
    cout<<solution(a)<<endl;
}
