#include <bits/stdc++.h>

using namespace std;

int decode(string str){
    int counts[str.length()+1];
    counts[0] = 1;
    counts[1] = 1;

    for(int i = 2; i <= str.length(); i++){
        counts[i] = 0;

        if(str[i-1] > '0')
            counts[i] = counts[i-1];
        if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1] < '7'))
            counts[i] += counts[i-2];
    }

    return counts[str.length()];
}
int main(){
    string str;
    cin>>str;

    cout<<decode(str)<<endl;
}
