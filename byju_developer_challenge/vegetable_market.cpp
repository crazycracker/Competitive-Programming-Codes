#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    vector< pair< long long int , long long int > > vec;
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    sort(arr,arr+n);

    long long int sum = 0, k = n, j = 0;

    for(int i = arr[0]; i <= arr[n-1]; i++){
        if(i == arr[j]){
            vec.push_back(make_pair(i*(k-j) + sum, i));
            sum += i;
            j++;
        }else{
            vec.push_back(make_pair(i*(k-j) + sum, i));
        }
    }

    map< long long int, long long int > m;

    int len = vec.size();

    j = 0;

    for(int i = min((long long int)1,vec[0].first); i <= vec[len-1].first; i++){
        if(i == vec[j].first){
            m[i] = vec[j].second;
            j++;
        }else{
            m[i] = vec[j].second;
        }
    }
    int q;
    cin>>q;

    while(q--){
        cin>>k;
        if(m.find(k) != m.end())
            cout<<m[k]<<endl;
        else
            cout<<"-1"<<endl;
    }
}
