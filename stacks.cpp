#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];

        bool strict = true;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i-1])
                continue;
            else{
                strict = false;
                break;
            }
        }

        if(strict){
            cout<<"1 "<<arr[n-1]<<endl;
        }else{
            vector<int> vec;
            int currMax = arr[0], k = 0;

            for(int i = 1; i < n; i++){
                if(arr[i] < currMax){
                    currMax = arr[i];
                }else{
                    vec.push_back(arr[i-1]);
                }
            }

            for(int i = 0; i < vec.size(); i++){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
    }
}
