#include <bits/stdc++.h>
#include <thread>

using namespace std;

void function1(){
    cout<<"hello world"<<endl;
}
int main(){
    thread t1(function1);

    try{

        for(int i = 0; i < 100; i++)
            cout<<"main: "<<i<<endl;
    }catch(...){
        t1.join();
        throw;
    }

    t1.join();
    return 0;
}
