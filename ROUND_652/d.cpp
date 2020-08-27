#include <bits/stdc++.h>
#define ll long long int
#define ar array
#define pb(x)   push_back(x)
using namespace std;

const int maxn = 2e5+10;
const int p = 571373;
const int maxm = 2e4+10;
const int INF = 0x3f3f3f3f;
const ll LINF = 3e17+1;
const int mod = 998244353;
int n, m, k,pp,T;
int w[maxn], d[maxn], u[maxn], v[maxn];
bool vis[maxn];
vector<int>vec[maxn];
queue<int>que;
stack<int>stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        vec[u[i]].pb(i);
        vec[v[i]].pb(i);
        d[u[i]]--, d[v[i]]--;
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] >= 0)  que.push(i);
    }
    while (!que.empty())
    {
        int tmp = que.front(); que.pop();
        for (int in: vec[tmp])
        {
            if (vis[in])    continue ;
            vis[in] = 1;
            d[u[in]]++, d[v[in]]++;
            if (d[u[in]] == 0) que.push(u[in]);
            if (d[v[in]] == 0) que.push(v[in]);
            stk.push(in);
        }
    }
     if (stk.size() < m)
        {
            cout << "DEAD" << endl;
        }
        else
        {
            cout << "ALIVE" << endl;
            while (!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
        }




    return 0;
}
