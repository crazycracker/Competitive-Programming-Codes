#include <bits/stdc++.h>

using namespace std;

int divi[1000001];
int tree[3 * 100001];
int arr[100001];

void getPrimes(){
    divi[1] = 1;

    for(int i = 2; i < 1000010; i += 2)
        divi[i] = 2;
    for(int i = 3; i < 1000010; i += 2){
        if(divi[i] == 0){
            divi[i] = i;
            for(int j = 2 * i; j < 1000010; j += i){
                if(divi[j] == 0)
                    divi[j] = i;
            }
        }
    }
    return;
}

void trees(int node, int start, int endd){
    if(start == endd){
        tree[node] = divi[arr[start]];
        arr[start] /= divi[arr[start]];
        return;
    }
    int mid = (start + endd)/2;
    trees(node*2, start,mid);
    trees(node*2 + 1, mid+1, endd);

    tree[node] = max(tree[node*2], tree[node*2 + 1]);
    return;
}

void update(int node, int start, int endd, int i, int j){
    if(tree[node] == 1)
        return;
    if(start > j)
        return;
    if(endd < i)
        return;

    if(start == endd){
        tree[node] = divi[arr[start]];
        arr[start] /= divi[arr[start]];
        return;
    }
    int mid = (start + endd)/2;
    update(node*2, start,mid,i,j);
    update(node*2 + 1, mid+1, endd,i,j);

    tree[node] = max(tree[node*2], tree[node*2 + 1]);
}

int query(int node, int start, int endd, int i, int j){
    if(tree[node] == 1)
        return 1;

    if(start > j)
        return 0;
    if(endd < i)
        return 0;

    if(i <= start && j >= endd)
        return tree[node];
    int mid = (start + endd)/2;
    int k = query(node*2, start,mid,i,j);
    int l = query(node*2 + 1, mid+1, endd,i,j);

    return max(k,l);
}

int main(){
    getPrimes();
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        trees(1,1,n);

        while(m--){
            int type,l,r;
            cin>>type>>l>>r;

            if(type){
                cout<<query(1,1,n,l,r)<<endl;
            }else
                update(1,1,n,l,r);
        }
    }
}
