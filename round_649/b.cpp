#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];

        for(int i = 1; i <= n; i++){
            cin>>arr[i];
        }
        vector<int> vec;

        for(int i = 1; i <= n; i++){
            if(i == 1 || i == n || ((arr[i-1] < arr[i]) != (arr[i] < arr[i+1])))
                vec.push_back(arr[i]);
        }
        int s = vec.size();
        cout<<s<<'\n';
        for(int i = 0; i < s; i++){
            cout<<vec[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
