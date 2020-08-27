#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

/*void findNthTerm(long long int A[], long long int B[], int M, int N){
    long long int result = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            long long int fib[max(2,N)];
            fib[0] = A[i]%MOD;
            fib[1] = B[j]%MOD;
            for(int k = 2; k < N; k++){
                fib[k] = (fib[k-1] + fib[k-2])%MOD;
            }
            result = (result + fib[N-1])%MOD;
            result %= MOD;
        }
    }

    cout<<result<<endl;
}*/
long long l,r;

void matmult(long long a[][2],long long b[][2],long long c[][2]){
  int i,j,k;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      c[i][j]=0;
      for(k=0;k<2;k++){
        c[i][j]+=(a[i][k]*b[k][j])%MOD;
        c[i][j]=c[i][j];
      }
    }
  }
}
void matpow(long long Z[][2],int n,long long ans[][2]){
  long long temp[2][2];
  ans[0][0]=1;ans[1][0]=0;ans[0][1]=0;ans[1][1]=1;
  int i,j;
  while(n>0){
    if(n&1){
      matmult(ans,Z,temp);
      for(i=0;i<2;i++) for(j=0;j<2;j++) ans[i][j]=temp[i][j];
    }
    matmult(Z,Z,temp);
    for(i=0;i<2;i++) for(j=0;j<2;j++) Z[i][j]=temp[i][j];
    n>>=1;
  }
  return;
}
void findFibonacci(long long n){
  long long fib;
  long long int Z[2][2]={{1,1},{1,0}},result[2][2];//modify matrix a[][] for other recurrence relations
  matpow(Z,n-2,result);
  l = result[0][0];
  r = result[0][1]; //final multiplication of Z^(n-2) with the initial terms of the series
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int m,n;
        cin>>m>>n;
        long long int a[m],b[m],result = 0, bsum = 0, asum = 0;

        for(int i = 0; i < m; i++){
            cin>>a[i];
            asum += a[i];
            asum %= MOD;
        }

        for(int i = 0; i < m; i++){
            cin>>b[i];
            bsum += b[i];
            bsum %= MOD;
        }

        if(n == 1)
            result = (((m*asum)%MOD))%MOD;
        else if(n == 2)
            result = (((m*bsum)%MOD))%MOD;
        else{
            findFibonacci(n);
            result = ((((m * l)%MOD) *(bsum))%MOD + ((((m * r)%MOD)*(asum))%MOD))%MOD;
            result %= MOD;
        }

        cout<<result<<endl;
        //findNthTerm(a,b,m,n);
    }
}
