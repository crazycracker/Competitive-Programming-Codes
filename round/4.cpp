#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string str;
    cin>>str;

    int counts = 0;

    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == str[i+1]){
            if(i + 2 < str.length()){
                if(str[i+2] == 'R'){
                    if(str[i+1] == 'B')
                        str[i+1] = 'G';
                    else if(str[i+1] == 'G')
                        str[i+1] = 'B';
                    else if(str[i+1] == 'R')
                        str[i+1] = 'B';
                }else if(str[i+2] == 'G'){
                    if(str[i+1] == 'B')
                        str[i+1] = 'R';
                    else if(str[i+1] == 'R')
                        str[i+1] = 'B';
                    else if(str[i+1] == 'G')
                        str[i+1] = 'R';
                }else if(str[i+2] == 'B'){
                    if(str[i+1] == 'R')
                        str[i+1] = 'G';
                    else if(str[i+1] == 'G')
                        str[i+1] = 'R';
                    else if(str[i+1] == 'B')
                        str[i+1] = 'R';
                }
            }else{
                if(str[i+1] == 'R')
                    str[i+1] = 'G';
                else if(str[i+1] == 'G')
                    str[i+1] = 'B';
                else if(str[i+1] == 'B')
                    str[i+1] = 'G';
            }
            counts++;
        }
    }
    cout<<counts<<endl;
    cout<<str<<endl;
}
