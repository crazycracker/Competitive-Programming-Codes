#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long l,r;

int TrailingZeros(int n)
{
    int counts = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        counts += n / i;

    return counts;
}

void matmult( long long a[][2], long long b[][2], long long c[][2]){
  int i,j,k;

  for(i = 0;i < 2; i++){
    for(j = 0;j < 2; j++){
      c[i][j]=0;
      for(k = 0;k < 2; k++){
        c[i][j]+=(a[i][k]*b[k][j])%MOD;
        c[i][j]=c[i][j];
      }
    }
  }
}

void matpow( long long Z[][2], long long int n, long long ans[][2]){
   long long temp[2][2];

  ans[0][0]=1;
  ans[1][0]=0;
  ans[0][1]=0;
  ans[1][1]=1;

  int i,j;
  while(n>0){

    if(n&1){
      matmult(ans,Z,temp);
      for(i = 0;i < 2;i++)
        for(j = 0;j < 2;j++)
            ans[i][j]=temp[i][j];
    }
    matmult(Z,Z,temp);

    for(i = 0;i < 2;i++)
        for(j = 0;j < 2;j++)
            Z[i][j]=temp[i][j];
    n>>=1;
  }
  return;
}

 long long int findFibonacci( long long n){
   long long int Z[2][2]={{1,1},{1,0}},result[2][2];

  matpow(Z,n-2,result);

  l = result[0][0];
  r = result[0][1];

  return (l + r);
}

vector< long long int> factorize( long long int a){
     long long int b,c;
    b = a;
    c = a;
     long long int cnt1,cnt2;
    cnt1 = cnt2 = 0;

    while(b%2 == 0){
        cnt1++;
        b /= 2;
    }
    while(c%5 == 0)
    {
        cnt2++;
        c /= 5;
    }
    vector< long long int> vec;
   // cout<<cnt1<<" "<<cnt2<<endl;
    vec.push_back(cnt1);
    vec.push_back(cnt2);
    return vec;
}
int main()
{
    int t;
    cin>>t;

    while(t--){
         long long int a,b,c,d;
        cin>>a>>b;
        c = TrailingZeros(a);
        d = TrailingZeros(b);
         long long int n;
        cin>>n;

        if(n < 2 && n > 0){
            if(n == 0)
                cout<<c<<endl;
            else
                cout<<d<<endl;
        }else if(n < 0){
            cout<<"N should be positive"<<endl;
        }else{
            long long int p1,p2;
            p1 = findFibonacci(n-1);
            p2 = findFibonacci(n);
            vector<long long int> x1,x2;
            x1 = factorize(a);
            x2 = factorize(b);

            cout<<min(( long long int)(x1[0]*p1 + x2[0]*p2 + MOD)%MOD,( long long int)(x1[1]*p1 + x2[1]*p2 + MOD)%MOD)<<endl;
        }
    }
}
