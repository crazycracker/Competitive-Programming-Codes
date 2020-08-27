#include <bits/stdc++.h>

using namespace std;

bool pres[100010];

struct node{
    int val;
    int index;
};

int compare(const void *a, const void *b){
    struct node *s1 = (struct node*)a;
    struct node *s2 = (struct node*)b;

    return s1->val < s2->val;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        memset(pres,false,sizeof(pres));

        struct node Nodes[n];

        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            pres[x] = true;
            Nodes[i].val = x;
            Nodes[i].index = i + 1;
        }

        qsort(Nodes,n,sizeof(struct node),compare);

        int i = 0;
        bool flag = false;

        while(i+1 < n){
            int temp = Nodes[i].val;
            int count = 0;

            while(temp == Nodes[i].val){
                if(pres[Nodes[i].index]){
                    count++;
                }
                i++;
            }

            if(count >= 2){
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"Truly Happy"<<endl;
        }else{
            cout<<"Poor Chef"<<endl;
        }
    }
}
