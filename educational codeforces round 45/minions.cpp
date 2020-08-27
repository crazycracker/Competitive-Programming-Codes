#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
const int N=400005;
int n;
priority_queue<int> q;
PI a[N];
bool check(int k){
	ll sum=0;
	while(q.size())q.pop();
	for(int i=1;i<k;i++){
		sum+=a[i].second; q.push(a[i].second);
	}
	for(int i=k;i<=n;i++){
		sum+=a[i].second; q.push(a[i].second);
		if(q.size()>k){
			sum-=q.top(); q.pop();
		}
		if(sum<=(ll)a[i].first*k)return 1;
	}
	return 0;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i].first=read(); a[i].second=read();
		}
		sort(&a[1],&a[n+1]); reverse(&a[1],&a[n+1]);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1; mid++;
			if(check(mid))l=mid; else r=mid-1;
		}
		writeln(l);
	}
}
