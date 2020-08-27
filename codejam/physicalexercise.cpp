#include <bits/stdc++.h>

using namespace std;

struct node{
    float x,y;
};

float distance(struct node *a, struct node *b){
    return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        struct node a[n],b[m],c[k];

        for(int i = 0; i < n;i++){
            cin>>a[i].x>>a[i].y;
        }
        for(int i = 0; i < m;i++){
            cin>>b[i].x>>b[i].y;
        }
        for(int i = 0; i < k;i++){
            cin>>c[i].x>>c[i].y;
        }

        float ans = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                float ij = distance(&a[i],&b[j]);
                for(int l = 0; l < k; l++){
                    float ik = distance(&a[i],&c[l]);
                    float jk = distance(&b[j],&c[l]);

                    ans = ij + min(jk, ik);
                }
            }
        }
        cout<<ans<<'\n';
    }
}
