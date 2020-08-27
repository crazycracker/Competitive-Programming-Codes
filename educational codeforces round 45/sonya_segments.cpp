#include <bits/stdc++.h>

using namespace std;

struct node{
    long long int l,r;
};

int compare(const void *a, const void *b){
    struct node *s1,*s2;
    s1 = (struct node*)a;
    s2 = (struct node*)b;

    if(s1->l == s2->l){
        return s1->r > s2->r;
    }
    return s1->l > s2->l;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        struct node m[n];

        for(int i = 0; i < n; i++){
            scanf("%lld%lld", &m[i].l, &m[i].r);
        }

        qsort(m,n,sizeof(struct node),compare);

        for(int i = 0; i < n; i++){
            long long int starting,ending;
            starting = m[i].l;
            ending   = m[i].r;

            for(int j = i + 1; j < n; j++){
                if(m[i].l > ending){
                    ending = m[i].r;
                    cnt++;
                }
            }

            ans += ncr(n,cnt);
        }

        cout<<ans<<endl;
    }
}
