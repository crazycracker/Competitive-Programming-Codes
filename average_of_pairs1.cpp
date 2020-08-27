#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL arr[100010];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%lld", arr+i);
        }
        sort(arr+1, arr+n+1);

        int cnt = 0;int ptl, ptr;
        for(int i=1; i<=n; i++){
            ptl = i; ptr = i;
            bool found = false;
            while(ptl>0 && ptr<=n && !found)
            {
                //cout<<ptl<<' '<<ptr<<' '<<arr[ptl]<<' '<<arr[ptr]<<endl;
                if((arr[ptl]+arr[ptr]==2*arr[i]) && ptl!=ptr){
                    //cout<<"OK"<<arr[ptl]<<' '<<arr[ptr]<<endl;
                    cnt++;
                    //found = true;
                }
                /*else{
                    if(arr[i]==arr[i-1]){
                        //cout<<i<<' '<<arr[ptl]<<' '<<arr[ptr]<<endl;
                        cnt++; found = true;
                    }
                    else if(arr[i]==arr[i+1]){
                        //cout<<i<<' '<<arr[ptl]<<' '<<arr[ptr]<<endl;
                        cnt++ ; found = true;
                    }
                }*/

                if(arr[ptl]+arr[ptr]>2*arr[i]) ptl--;
                else ptr++;
            }

        }

        printf("%d\n", cnt);
    }
}
