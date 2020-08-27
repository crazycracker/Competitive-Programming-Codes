#include <bits/stdc++.h>

using namespace std;

bool visited[100010];
vector<int> vec[100010];
int data[100010];
int value;

/*
    DFS algorithm to keep track of the visited nodes
*/
void dfs(int s){
    if(!visited[s]){
        value += data[s];
        visited[s] = true;

        for(int i = 0; i < vec[s].size(); i++){
            if(!visited[vec[s][i]]){
                dfs(vec[s][i]);
            }
        }
    }
    return;
}
int main(){
    int no_of_elements;
    cin>>no_of_elements;

    int no_of_rows;
    cin>>no_of_rows;


    int maxValue = 0;

    for(int i = 1; i <= no_of_elements; i++){
        cin>>data[i];
        maxValue = max(data[i], maxValue);
    }

    for(int i = 0; i < no_of_rows; i++){
        int x,y;
        cin>>x>>y;

        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for(int i = 1; i <= no_of_elements; i++){
        if(!visited[i]){
            value = 0;
            dfs(i);
            maxValue = max(maxValue,value);
        }
    }

    cout<<maxValue<<'\n';
    return 0;
}
