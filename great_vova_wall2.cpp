#include <bits/stdc++.h>
using namespace std;
int n, x, mx = 0;
stack <int> s;
int main (){
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x;
		mx = max (mx, x);
		if (!s.empty() && x > s.top ()) {
			cout << "NO";
			return 0;
		}
		if (!s.empty() && x == s.top())s.pop ();
        else s.push (x);
	}
	if (s.size () > 1 || s.size () == 1 && s.top () < mx)
        cout << "NO";
    else cout << "YES";
	return 0;
}
