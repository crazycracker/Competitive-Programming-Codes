#include <bits/stdc++.h>

using namespace std;

int ways = 0;
bool col[16],diag1[16],diag2[16],reserved[8][8];

void searchWays(int r){
    if(r == 8){
        ways++;
        return;
    }

    for(int i = 0; i < 8; i++){
        if(col[i] || diag1[r+i] || diag2[r-i+7] || reserved[r][i]){
            continue;
        }
        col[i] = diag1[r+i] = diag2[r-i+7] = true;
        searchWays(r+1);
        col[i] = diag1[r+i] = diag2[r-i+7] = false;
    }

}
int main(){
    for(int i = 0; i < 16; i++)
        col[i] = diag1[i] = diag2[i] = false;
    for(int i = 0;i < 8; i++){
        string s;
        cin>>s;

        for(int j = 0; j < 8; j++){
            reserved[i][j] = s[j] != '.';
        }
    }
    searchWays(0);
    cout<<ways;
}
