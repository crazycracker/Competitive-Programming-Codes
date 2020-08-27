#include <bits/stdc++.h>
using namespace std;
string s[1000];
int vis[1000];
int main()
{

    int n;
    cin >> n;
    int m = n * 2 - 2;
    bool b = false;
    string suf, pre;
    for(int i = 0; i < m; i++)
    {
        cin >> s[i];
        if (!b && s[i].size() == n-1)
        {
            pre = s[i];
            b = true;
        }
        if (b && s[i].size() == n-1)
            suf = s[i];
    }
    int cnt = 0;
    for(int i = 0; i < m; i++)
        if(s[i][0] == pre[0])
            cnt++;
    if(pre.substr(1) != suf.substr(0, n-2) || cnt < m/2)
        swap(suf, pre);
    for(int i = 0; i < m; i++)
    {
        if (s[i] == pre.substr(0, s[i].size()) && !vis[s[i].size()])
        {
            printf("P");
            vis[s[i].size()] = 1;
        }
        else
            printf("S");
    }
    printf("\n");

}
