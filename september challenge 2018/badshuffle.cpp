#include <bits/stdc++.h>

using namespace std;

void printArray (int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void printReverseArray (int arr[], int n)
{
    if(n%2){
        for (int i = n-1; i >= n/2 + 1; i--)
            printf("%d ", i+1);
        for(int i = 0; i < n/2 + 1; i++)
            printf("%d ", i+1);
        printf("\n");
    }else{
        for (int i = n-1; i >= 0; i--)
            printf("%d ", i+1);
        printf("\n");
    }
}
// A function to generate a random permutation of arr[]
void randomize ( int arr[], int n )
{
	// Use a different seed value so that we don't get same
	// result each time we run this program
	srand ( time(NULL) );

	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (int i = n-1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i+1);

		// Swap arr[i] with the element at random index
		swap(arr[i], arr[j]);
	}
}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    randomize(arr,n);
    printArray(arr,n);
    printReverseArray(arr,n);
}
