#include <bits/stdc++.h>

using namespace std;

long long int binarySearch(long long int arr[], long long int l, long long int r, long long int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

vector<long long int> check(long long int indices[], int l, int r, long long int x, long long int arr[]){
    long long int cnt1,cnt2, cnt3, cnt4;
    cnt1 = cnt2 = cnt3 = cnt4 = 0;
    while (l <= r)
    {
        int m = l + (r-l)/2;

        // Check if x is present at mid
        if (indices[m] == x)
            break;

        // If x greater, ignore left half
        if (indices[m] < x){
            l = m + 1;
            if(arr[m] > arr[x-1])
                cnt1++;
            else
                cnt3++;
        }

        // If x is smaller, ignore right half
        else{
            r = m - 1;
            if(arr[m] < arr[x-1])
                cnt2++;
            else
                cnt4++;
        }
    }

    vector<long long int> vec;
    vec.push_back(cnt1);
    vec.push_back(cnt2);
    vec.push_back(cnt3);
    vec.push_back(cnt4);

    return vec;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n,q,x;
        scanf("%lld%lld", &n, &q);

        long long int arr[n],indices[n],arr1[n];

        for(int i = 0; i < n; i++)
            indices[i] = i + 1;

        map< long long int, long long int> index;
        map< long long int , long long int> m;

        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
            arr1[i] = arr[i];
            index[arr[i]] = i;
        }
        sort(arr1,arr1+n);

        for(int i = 0; i < n; i++){
            m[arr1[i]] = i;
        }

        for(int i = 0; i < q; i++){
            scanf("%lld", &x);
            long long int k1 = binarySearch(arr,0,n-1,x);
            if(k1 == -1){
                if(m.find(x) != m.end()){
                    long long int miniCnt = 1e9;

                    vector<long long int> cnt = check(indices,0,n-1,index[x]+1,arr);
                 //   cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
                   // cout<<m[x]-cnt[2]<<" "<<(n - m[x] - 1 - cnt[3])<<endl;
                    if(cnt[0] <= (m[x] - cnt[2]) && cnt[1] <= (n - m[x] - 1 - cnt[3])){
                        miniCnt = abs(cnt[0] - cnt[1]) + min(cnt[0],cnt[1]);
                    }

                    if(miniCnt == 1e9)
                        printf("-1\n");
                    else
                        printf("%lld\n", miniCnt);
                }else{
                    printf("-1\n");
                }

            }else{
                printf("0\n");
            }
        }

    }
    return 0;
}

