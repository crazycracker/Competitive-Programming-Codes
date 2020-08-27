#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;

char str[1000001];

int main(){

    scanf("%s", str);
    int n = strlen(str);

    char prev = str[0];
    int cur = 1, ans = 0;

    for(int i = 1; i < n; i++){
        if(!(str[i] ^ prev)){
            ++cur;
        }else{
            if(cur > ans)
                ans = cur;
            prev = str[i];
            cur = 1;
        }
    }
    if(cur > ans)
        ans = cur;
    cout<<ans<<'\n';
    return 0;
}

