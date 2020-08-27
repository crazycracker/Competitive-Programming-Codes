#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int sum = 0,num,b;

	for(int i = 0; i < n; i++){
        cin>>num;
        if(i == k)
            continue;
        sum += num;
	}
	cin>>b;

	b = (b - (sum/2));

	if(b != 0)
        cout<<abs(b)<<endl;
    else
        cout<<"fair"<<endl;
}
