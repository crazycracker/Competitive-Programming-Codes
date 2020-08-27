/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        string s;
        unsigned long long int n,i;

        cin>>s;
        cin>>n;

        unsigned long long int arr[150], countA, countB, len = s.length(),ans;
        memset(arr,0,sizeof(arr));
        countA = countB = 0;

        for(i = 0; i < 150; i++){
            ans = 0;
            for(int j = 0; j < len; j++){
                if(s[j] == 'a')
                    countA++;
                else
                    countB++;

                if(countA > countB)
                    ans++;
            }

            arr[i] = ans;
        }

        vector<unsigned long long int> vec;

        for(i = 0; i < 149; i++){
            if(arr[i] == arr[i+1])
                continue;
            vec.push_back(arr[i]);
        }
        vec.push_back(arr[149]);

        unsigned long long int size = vec.size();

	    ans = 0;
	    if(n >= size){
	        for(i = 0; i < size - 1; i++){
	            ans += vec[i];
	        }

	        ans += (unsigned long long int)((n - size + 1)*vec[size-1]);
	    }else{
	        for(i = 0; i < n; i++)
	            ans += vec[i];
	    }

	    cout<<ans<<endl;

    }
    return 0;
}
