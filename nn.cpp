#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int main(){
    int n,r;

    cin>>n>>r;

    double ratios = (sin(PI/n)/(1 - (-sin(PI/n))));
    double ra = ratios*r/(1-2*ratios);
    ra *= 1000;
    ra = round(ra);
    ra /= 1000;
    printf("%.6f\n",ra);
}
