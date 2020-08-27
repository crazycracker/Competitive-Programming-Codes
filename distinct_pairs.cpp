#include <iostream>
#include <stdio.h>
#include <unordered_set>
using namespace std;

void pairWithEqualSum(int A[], int B[], int n, int m, int k)
{
    // Map1 to store pairs and their sum,
    // An ordered map is used here to avoid
    // duplicate pairs of elements
    map<pair<int, int>, int> mp;

    // Insert all unique pairs and their
    // corresponding sum in the map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pair<int, int> p = make_pair(A[i], B[j]);

            mp[p] = A[i] + B[j];
        }
    }

    // Second map with key as sum and value as
    // list of pairs with that sum
    map<int, vector<pair<int, int> > > mp2;

    // Start iterating first map mp and insert all
    // pairs with corresponding sum in second map mp2
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        int sum = itr->second;
        pair<int, int> pair = itr->first;

        mp2[sum].push_back(pair);
    }

    // Traverse the second map mp2, and for sum
    // with more than one pair, print all pairs
    // and the corresponding sum
    int counts = 0;
    for (auto itr = mp2.begin(); itr != mp2.end(); itr++) {
        if(counts < k)
            for (int i = 0; i < 1; i++) {
                cout<< itr->second[i].first <<" "<< itr->second[i].second <<endl;
            }
        else
            break;
    }
    return;
}

int main(){
    int n,m;

    scanf("%d%d", &n, &m);
    int a[n];
    int b[m];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    pairWithEqualSum(a,b,n,m,k);
    return 0;
}
