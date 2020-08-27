#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int x;
    stack<int> st;

    for(int i = 0; i < n; i++){
        cin>>x;

        x = x % 2;

        if(!st.empty() && (st.top() == x))
            st.pop();
        else
            st.push(x);
    }


    if(st.size() <= 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
