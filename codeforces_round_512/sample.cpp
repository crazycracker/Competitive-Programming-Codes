#include <bits/stdc++.h>

using namespace std;

int gemini(int n){
    if(n > 100)
        return n-10;
    else
        return (gemini(gemini(n+11)));
}
int main(){
    printf("%d", gemini(95));
}
