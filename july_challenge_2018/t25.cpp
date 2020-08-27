#include <bits/stdc++.h>

using namespace std;

vector<long long int> vec;
long long int n,k;

long long int lenOfLongSubarr(long long int k){
    map<int, int> um;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        if (sum == k)
            maxLen = i + 1;
        if (um.find(sum) == um.end())
            um[sum] = i;
        if (um.find(sum - k) != um.end()) {
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
    return maxLen;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        long long int x,totalSum = 0;
        cin>>n>>k;
        vec.clear();

        for(int i = 0; i < n; i++)
        {
            cin>>x;
            vec.push_back(x);
        }
        long long int maxlen = 0,rem = 0;
        for(int i = k; i >= k/2; i--){
            x = lenOfLongSubarr(i);
            if(x > maxlen){
                maxlen = x;
                rem = k - i;
            }
        }
        cout<<maxlen<<" "<<rem<<endl;
    }
}
