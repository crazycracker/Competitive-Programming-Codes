#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];

        for(int i = 0; i < n; i++)
            cin>>arr[i];

        sort(arr, arr+n);

        int answer = 1;

        int i = 0;
        int previousCount = 0;

        while(i < n){
            int temp = arr[i];
            int freshCount = previousCount;

            while(i < n && temp == arr[i]){
                freshCount++;
                i++;
            }

            if(answer+freshCount-1 >= temp){
                answer += freshCount;
                previousCount = 0;
            }else{
                previousCount = freshCount;
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}
