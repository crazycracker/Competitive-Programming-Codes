// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &vec) {
    pair<int,int> p[vec.size()],r[vec.size()];
    long long int ans = -1, n = vec.size(),i,j;

    for(i = 0; i < n; i++){
        p[i] = make_pair(vec[i],i);
    }

    sort(p,p+vec.size());
    map<int,int> m;

    for(i = 0,j = 0; i < n; i++){
        if(m.find(p[i].first) == m.end()){
            m[p[i].first] = j;
            r[j] = make_pair(p[i].second,p[i].second);
            j++;
        }else{
            int mini, maxi, val;
            mini = r[m[p[i].first]].first;
            maxi = r[m[p[i].first]].second;
            val = p[i].second;

            if(val < mini){
                r[m[p[i].first]].first = val;
            }else if(val > maxi){
                r[m[p[i].first]].second = val;
            }
        }
    }
    for(i = 0, j = 1; j < n; i++,j++){
        long long int val = abs(max(r[m[p[i].first]].second,r[m[p[j].first]].second)-min(r[m[p[i].first]].first,r[m[p[j].first]].first));
        if(ans < val){
            ans = val;
        }
    }

    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> vec;

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    cout<<solution(vec)<<endl;
}
