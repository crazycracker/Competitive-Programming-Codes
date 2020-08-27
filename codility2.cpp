// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int count(int n){
    int c = 0;

    while(n){
        if(n%10 == 1){
            c++;
        }
        n = n/10;
    }

    return c;
}

int solution(int n) {
    int ans = 0;

    for(int i = 0; i <= n; i++){
        ans += count(i);
    }

    return ans;
}
