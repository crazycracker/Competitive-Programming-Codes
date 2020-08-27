#include <stdlib.h>
#include <stdio.h>

int cnt = 0;
/* Reverses arr[0..i] */
void flip(long long int arr[], int i)
{
    long long int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

// Returns index of the
// maximum element in
// arr[0..n-1]
int findMax(long long int arr[], int n)
{
int mi, i;
for (mi = 0, i = 0; i < n; ++i)
    if (arr[i] >= arr[mi])
            mi = i;
return mi;
}

// The main function that
// sorts given array using
// flip operations
int pancakeSort(long long int *arr, int n)
{
    // Start from the complete
    // array and one by one
    // reduce current size
    // by one
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        // Find index of the
        // maximum element in
        // arr[0..curr_size-1]
        int mi = findMax(arr, curr_size);

        // Move the maximum
        // element to end of
        // current array if
        // it's not already
        // at the end
        if (mi != curr_size-1)
        {
            // To move at the end,
            // first move maximum
            // number to beginning
            printf("%lld\n", arr[mi]);
            if(mi != 0){
                flip(arr, mi);
                cnt++;
            }

            // Now move the maximum
            // number to end by
            // reversing current array
            flip(arr, curr_size-1);
            cnt++;
        }
    }
}

// Driver program to test above function
int main()
{
    int n;
    scanf("%d", &n);

    long long int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%lld",&arr[i]);

    pancakeSort(arr, n);
    //printArray(arr, n);
    printf("%d\n", cnt);
    return 0;
}
