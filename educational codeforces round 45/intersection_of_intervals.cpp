#include <bits/stdc++.h>

using namespace std;

map<string,int> mapp;

string to_string(int val){
    string str;
    while(val){
        str += (val%10 + '0');
        val /= 10;
    }
    int i = 0, j = str.length()-1;
    while(i < j){
        swap(str[i],str[j]);
        i++,j--;
    }
    return str;
}
struct Interval
{
    int s, e;
};

// Function used in sort
bool mycomp(Interval a, Interval b)
{   return a.s > b.s; }

void mergeIntervals(Interval arr[], int n)
{
    // Sort Intervals in decreasing order of
    // start time
    sort(arr, arr+n, mycomp);

    int index = 0; // Stores index of last element
    // in output array (modified arr[])

    // Traverse all input Intervals
    for (int i=0; i<n; i++)
    {
        // If this is not first Interval and overlaps
        // with the previous one
        if (index != 0 && arr[index-1].s <= arr[i].e)
        {
            while (index != 0 && arr[index-1].s <= arr[i].e)
            {
                // Merge previous and current Intervals
                arr[index-1].e = max(arr[index-1].e, arr[i].e);
                arr[index-1].s = min(arr[index-1].s, arr[i].s);
                index--;
            }
        }
        else // Doesn't overlap with previous, add to
            // solution
            arr[index] = arr[i];

        index++;
    }
    string str;
    for (int i = index-1; i >= 0; i--){
        str += "[";
        str += to_string(arr[i].s);
        str += ", ";
        str += to_string(arr[i].e);
        str += "] ";
    }
    mapp[str]++;
 //   cout<<endl;
}

bool check(vector<int> vec){
    int n = vec.size(),maxi = 0;

    for(int i = 0,j = 1; j < n ; i += 2,j += 2){
        if(vec[i] < vec[j]){
            if(maxi < vec[j]){
                maxi = vec[j];
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}

void solve(){
    mapp.clear();
    int n;
    cin>>n;

    vector<int> vec;

    for(int i = 0; i < n; i++){
        vec.push_back(i+1);
    }

    do{
        if(check(vec)){
            Interval arr[n/2];
            int k = 0;
            for(int i = 0,j = 1; j < n; i+=2,j += 2){
                arr[k].s = vec[i];
                arr[k].e = vec[j];
                k++;
            }
            mergeIntervals(arr,n/2);
        }
    }while(next_permutation(vec.begin(), vec.end()));


    for(map<string,int>::iterator it = mapp.begin(); it!=mapp.end(); it++){
        cout<<it->first << " "<< it->second<<endl;
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
