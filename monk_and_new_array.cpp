#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

long long int grid[M][M];

long long int findMin(int a, int b, int m){
    int i,j;
    i = j = 0;
    long long int ans = LONG_MAX, val;

    while(i < m && j < m){
        val = abs(grid[a][i] - grid[b][j]);
        if(grid[a][i] < grid[b][j]){
            i++;
        }else if(grid[a][i] > grid[b][j]){
            j++;
        }else{
            return 0;
        }
        ans = min(ans,val);
    }

    while(j < m){
        ans = min(ans,abs(grid[a][m-1]-grid[b][j]));
        j++;
    }
    
    while(i < m){
        ans = min(ans,abs(grid[a][i]-grid[b][m-1]));
        i++;
    }

    return ans;
}
int main(){
    freopen("input.txt", "r",stdin);
    int n,m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
        sort(grid[i],grid[i]+m);
    }

    long long int ans = LONG_MAX;

    for(int i = 0; i < n-1; i++){
        ans = min(ans, findMin(i,i+1,m));
    }

    cout<<ans<<endl;
}