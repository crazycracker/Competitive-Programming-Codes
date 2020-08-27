#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}
int printModeMedian(int a[], int n, int l, int r)
{
    // The output array b[] will
    // have sorted array
    int b[r-l+1];

    // variable to store max of
    // input array which will
    // to have size of count array
    int max = *max_element(a+l-1, a+r);

    // auxiliary(count) array to
    // store count. Initialize
    // count array as 0. Size
    // of count array will be
    // equal to (max + 1).
    int t = max + 1;
    int count[t];
    for (int i = 0; i < t; i++)
        count[i] = 0;

    // Store count of each element
    // of input array
    for (int i = l-1; i < r; i++)
        count[a[i]]++;

    // mode is the index with maximum count
    int mode = 0;
    int k = count[0];
    for (int i = 1; i < t; i++)
    {
        if (count[i] >= k)
        {
            k = count[i];
            mode = i;
        }
    }

    // Update count[] array with sum
    for (int i = 1; i < t; i++)
        count[i] = count[i] + count[i-1];

    // Sorted output array b[]
    // to calculate median
    for (int i = l-1; i < r; i++)
    {
        b[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    // Median according to odd and even
    // array size respectively.
    float median;
    if ((r-l+1) % 2 != 0)
        median = b[(r-l+1)/2];
    else
        median = (b[((r-l+1)-1)/2] +
                  b[((r-l+1)/2)])/2.0;

    cout<<median<<" "<<mode<<endl;
    return lcm(floor(median), mode);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        int arr[n],x,l,r;

        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < q; i++){
            cin>>x;
            if(x == 1){
                cin>>l>>r;
                cout<<printModeMedian(arr,n,l,r)<<endl;
            }else{
                cin>>l>>r;
                arr[l-1] = r;
            }
        }
    }
}
