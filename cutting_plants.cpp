#include <bits/stdc++.h>

using namespace std;

int n;
int a[100010], b[100010];

vector< pair<int,int> > getSetIndices(int startIndex, int endIndex){
    bool inClump = false;
    vector< pair<int,int> > vec;
    int starting, ending;
    starting = ending = -1;
    for(int i = startIndex + 1; i <= endIndex; i++){
        if(b[i] == b[i-1]){
            if(!inClump){
                starting = i - 1;
                inClump = true;
            }
            ending = i;
        }else{
            if(inClump){
                vec.push_back(make_pair(starting, ending));
                //cout<<starting<<" "<<ending<<endl;
                inClump = false;
                starting = ending = -1;
            }
        }
    }
    if(starting != -1){
        vec.push_back(make_pair(starting, ending));
    }

    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    return vec;
}
int numberOfDistinctElements(int startIndex, int endIndex){
   // cout<<startIndex<<" "<<endIndex<<endl;
    if(startIndex == endIndex)
        return 1;
    int c = 0;
    vector< pair<int,int> > vec = getSetIndices(startIndex, endIndex);
    /*for(int i = startIndex; i < endIndex;i++){
        int index = i;
        cout<<i<<" "<<index<<endl;
        while(i < endIndex && b[index] == b[i+1]){
            i++;
        }
        c++;
    }*/
    return c;
}
int check(){
    for(int i = 0; i < n; i++){
        if(a[i] < b[i])
            return -1;
    }

    for(int i = 0; i < n; i++){
        if(a[i] != b[i])
            return 1;
    }

    return 0;
}

void countOfOperations(){
    vector< pair<int,int> > vec;
    bool flag = true;
    int startIndex, endIndex;
    startIndex = endIndex = -1;

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(flag){
                startIndex = i;
                endIndex = i;
                flag = false;
            }else{
                endIndex = i;
            }
        }else{
            if(startIndex != -1 && endIndex != -1)
            {
                vec.push_back(make_pair(startIndex, endIndex));
                flag = true;
                startIndex = endIndex = -1;
            }
        }
    }

    if(startIndex != -1 && endIndex != -1)
    {
        vec.push_back(make_pair(startIndex, endIndex));
        startIndex = endIndex = -1;
    }

    int result = 0;
    for(int i = 0; i < vec.size(); i++){
        result += numberOfDistinctElements(vec[i].first, vec[i].second);
    }

    cout<<result<<endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];

        for(int i = 0; i < n; i++)
            cin>>b[i];

        int c = check();

        if(c <= 0)
            cout<<c<<endl;
        else
            countOfOperations();

    }

    return 0;
}
