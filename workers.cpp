#include <bits/stdc++.h>

using namespace std;

struct node{
    int cost;
    int type;
};

int compare(const void *a, const void *b){
    struct node *s1 = (struct node *)a;
    struct node *s2 = (struct node *)b;

    if(s1->type == s2->type)
        return s1->cost > s2->cost;
    return (s1->type < s2->type);
}

int main(){
    int n;
    cin>>n;

    struct node *a = (struct node*)malloc(n*sizeof(struct node));

    for(int i = 0; i < n; i++){
        cin>>a[i].cost;
    }

    for(int i = 0; i < n; i++){
        cin>>a[i].type;
    }

    qsort(a,n,sizeof(struct node), compare);
    int oneStart, twoStart, threeStart;
    oneStart = twoStart = threeStart = 1000010;

    for(int i = 0; i < n; i++){
        if(a[i].type == 3 && threeStart > a[i].cost){
            threeStart = a[i].cost;
        }else if(a[i].type == 2 && twoStart > a[i].cost){
            twoStart = a[i].cost;
        }else if(a[i].type == 1 && oneStart > a[i].cost){
            oneStart = a[i].cost;
        }
    }

    cout<<(threeStart < (oneStart + twoStart) ? threeStart : oneStart + twoStart);
}
