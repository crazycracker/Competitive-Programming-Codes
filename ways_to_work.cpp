#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int MAX = 1000001;

int fact[maxn];
vector<int> vec(MAX);

void permuteHelper(int arr[], int index, int length, int n){
    if(index >= length - 1){ //If we are at the last element - nothing left to permute
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        if(length > 0)
            cout<<arr[length-1]<<endl;
        return;
    }

    for(int i = index; i < length; i++){ //For each index in the sub array arr[index...end]

        //Swap the elements at indices index and i
        int t = arr[index];
        arr[index] = arr[i];
        arr[i] = t;

        //Recurse on the sub array arr[index+1...end]
        permuteHelper(arr, index+1,length,n);

        //Swap the elements back
        t = arr[index];
        arr[index] = arr[i];
        arr[i] = t;
    }
}

void permute(int arr[],int length,int n){
    permuteHelper(arr,0,length,n);
}

void initialize(){
    fact[0] = fact[1] = 1;

    for(int i = 2; i < maxn; i++)
        fact[i] = fact[i-1]*i;
}
int main(){
    initialize();
    int t;
    cin>>t;

    while(t--){
        int n,c;
        cin>>n>>c;

        int j = 0;
        while(fact[j] < c)
            j++;
        int arr[j];

        for(int i = 0; i < j; i++)
            arr[i] = i + 1;
        permute(arr,j,vec,n);
    }

}
