#include <bits/stdc++.h>

using namespace std;

int usingThreeElementApproach(int arr[], int n){
    long long int result = 0,temp;
    int counts[1010][2];
    memset(counts,0,sizeof(counts));

    sort(arr,arr+n);
    for(int i = 0;i < n; i++){
        int flag = (arr[i] < 0)?1:0;
        counts[abs(arr[i])][flag] = counts[abs(arr[i])][flag] + 1;
    }

    vector<int> vec;
    bool check[1010][2];
    memset(check,false,sizeof(check));

    for(int i = 0; i < n; i++){
        int flag = (arr[i] < 0)?1:0;
        if(!check[abs(arr[i])][flag]){
            vec.push_back(arr[i]);
            check[abs(arr[i])][flag] = true;
        }
    }
    n = vec.size();

    for(int i = 1; i < n; i++){
        int l = i - 1;
        int u = i + 1;

        while(l >= 0 && u < n){
            temp = vec[l] + vec[u];
            if((temp - 2 * vec[i]) == 0){
                //cout<<arr[l]<<" "<<arr[u]<<endl;
                long long int temp1 = (vec[l] < 0)?counts[-vec[l]][1]:counts[vec[l]][0];
                long long int temp2 = (vec[u] < 0)?counts[-vec[u]][1]:counts[vec[u]][0];

                result += (long long int)(temp1*temp2);
                //cout<<result<<endl;
                l--;
                u++;
            }else if(temp > 2*vec[i])
                l--;
            else if(temp < 2*vec[i])
                u++;
        }
    }

    for(int i = 0; i < n; i++){
        long long int temp1 = (vec[i] < 0)?counts[-vec[i]][1]:counts[vec[i]][0];
        result += (long long int)((temp1*(temp1-1))/2);
    }
    return result;
}

int main(){
    int t;
    //t = scanInt();
    cin>>t;
    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];

        for(int i = 0; i < n; i++){
           scanf("%d", &arr[i]);
        }

        //printf("%d\n",countPairs(arr,n));
        cout<<usingThreeElementApproach(arr,n)<<endl;
    }
}
