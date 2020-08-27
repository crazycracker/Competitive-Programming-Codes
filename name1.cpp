#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string a,b;
        cin>>a;
        cin>>b;

        int arr[26], arr1[26];

        memset(arr,0,sizeof(arr));
        memset(arr1,0,sizeof(arr1));

        fo(int i = 0; i < a.length(); i++){
            arr[a[i] - 97]++;
        }
        fo(int i = 0; i < b.length(); i++){
            arr[b[i] - 97]++;
        }

        string c="";

        int t;
        cin>>t;

        while(t--){
            cin>>a;
            c += a;
        }

        fo(int i = 0; i < c.length(); i++){
            arr1[c[i] - 97]++;
        }

        bool flag = true;

        fo(int i = 0; i < 26; i++){
            if(arr1[i] > arr[i]){
                flag = false;
                break;
            }
        }

        if(!flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}
