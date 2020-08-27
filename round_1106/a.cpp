#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    char M[n][n];

    for(int i = 0; i < n; i++){
        scanf("%s",M[i]);
    }

    int counts = 0;
    for(int i = 1,j = 1; i < n-1 && j < n-1; i++){
        for(int k = j; k < n-1; k++){
            if(M[i][k] == 'X'){
                if(M[i-1][k-1] == 'X' && M[i-1][k+1] == 'X' && M[i+1][k-1] == 'X' && M[i+1][k+1] == 'X')
                    counts++;
            }
        }
    }

    cout<<counts<<endl;
}
