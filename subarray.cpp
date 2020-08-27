#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int prefix[n+1];
    prefix[0] = 0;
    prefix[1] = arr[0];

    for(int i = 1; i < n; i++){
        prefix[i+1] = prefix[i] + arr[i];
    }

    int cnt = 1;
    vector< pair<int,int> > vec;
    vec.push_back(make_pair(1,n));

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(i == 1 && j == n)
                continue;
            double subSum = (prefix[j] - prefix[i-1])/(j - i + 1);
            double rangeSum = (prefix[n] - prefix[j] + prefix[i-1])/(n - j + i - 1);

            if(subSum > rangeSum){
                cnt++;
                vec.push_back(make_pair(i,j));
            }
        }
    }

    cout<<cnt<<endl;

    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    return 0;
}
