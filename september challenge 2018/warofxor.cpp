#include <bits/stdc++.h>

using namespace std;

int xorPairCount(vector<int> arr,int x)
{
    int n = arr.size();
	int result = 0; // Initialize result

	// create empty map that stores counts of
	// individual elements of array.
	unordered_map<int, int> m;

	for (int i=0; i<n ; i++)
	{
		int curr_xor = x^arr[i];

		// If there exist an element in map m
		// with XOR equals to x^arr[i], that means
		// there exist an element such that the
		// XOR of element with arr[i] is equal to
		// x, then increment count.
		if (m.find(curr_xor) != m.end())
			result += m[curr_xor];

		// Increment count of current element
		m[arr[i]]++;
	}


	// return total count of pairs with XOR equal to x
	return result;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n;

        vector<int> even,odd;

        for(int i = 0; i < n; i++){
            cin>>x;
            if(x%2){
                odd.push_back(x);
            }else
                even.push_back(x);
        }

        int pairs_of_two = xorPairCount(even,2) + xorPairCount(odd,2);
        int pairs_of_zero = xorPairCount(even,0) + xorPairCount(odd,0);

        cout<<((odd.size() * (odd.size() - 1))/2 + (even.size() * (even.size() - 1))/2) - (pairs_of_two+ pairs_of_zero) <<endl;
    }
}
