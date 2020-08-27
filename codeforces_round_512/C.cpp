#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
int pre[maxn];
string str;

int main()
{
    scanf("%d",&n);
    cin>>str;
    int len = str.length();
    int num = 0;
    for(int i=0;i<n;i++){
        if(str[i] != '0'){
            pre[++num] = str[i] - '0';
        }
    }
    if(num == 0){
        puts("YES");
        return 0;
    }
    n = num;
    int ans = 0;
    bool flag1 = false;
    for(int i=1;i<=n;i++){
        ans += pre[i];
        int x = 0,flag = 0;
        for(int j=i+1;j<=n;j++){
            x += pre[j];
            if(x > ans)break;
            if(x == ans){
                x = 0;
                if(j == n)flag = 1;
            }
        }
        if(flag){
            puts("YES");
            flag1 = true;
            break;
        }
    }
    if(flag1 == false){
        puts("NO");
    }
    return 0;
}
