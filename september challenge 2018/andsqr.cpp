#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        long long int n,q;
        scanf("%lld%lld", &n, &q);

        long long int arr[n],x,y;

        for(int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);

        int countArray[n][n],andArray[n][n];
        memset(countArray,0,sizeof(countArray));

        for(int i = 0; i < n; i++){
            if(isPerfectSquare(arr[i])){
                countArray[i][i] = 1;
            }
            andArray[i][i] = arr[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                andArray[i][j] = andArray[i][j-1] & arr[j];
                if(isPerfectSquare(andArray[i][j]))
                    countArray[i][j] = countArray[i][j-1] + 1;
            }
        }
        for(int i = 0; i < q; i++){
            scanf("%lld%lld", &x,&y);
            printf("%d\n",countArray[x-1][y-1]);
        }
    }
}
