#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int arr[n],socialCount,testCount;

    socialCount = testCount = 0;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == 1){
            testCount++;
        }
        else{
            socialCount++;
        }
    }
    int maxAbsValue = 0;

    for(int b = 0; b < n; b++){
        int test,social;
        test = testCount;
        social = socialCount;
        for(int i = 0; b + i*k < n; i++){
            int c = b + i*k;
            if(arr[c] == 1)
                test--;
            else
                social--;
        }
        for(int i = 1; b - i*k >= 0; i++){
            int c = b - i*k;
            if(arr[c] == 1)
                test--;
            else
                social--;
        }
        maxAbsValue = max(maxAbsValue, abs(test - social));
    }
    cout<<maxAbsValue<<endl;
}
