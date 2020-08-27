#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    string str;
    cin>>str;

    sort(str.begin(), str.end());
    int cnt = 0;
    for(int i = 11; i < n; i++){
        if(str[i] == '8')
            cnt++;
    }

    if(cnt % 2 == 0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
