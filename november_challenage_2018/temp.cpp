#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){

    int len = s.length();

    for(int i = 0, j = len-1; i < j; i++,j--){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        if(isPalindrome(s)){
            cout<<"YES"<<endl;
        }else{
            bool flag = false;
            for(int i = 0; i < s.length()-1; i++){
                int tempi,tempj,len = 0;
                tempi = i;
                tempj = tempi + 1;

                while(s[tempi] == s[tempj]){
                    if(tempi == tempj){
                        len += 1;
                    }else{
                        len += 2;
                    }

                    if(len == s.length()){
                        flag = true;
                        break;
                    }
                    tempi--;
                    tempj++;
                    if(tempi < 0){
                        tempi = s.length()-1;
                    }
                    if(tempj > s.length()-1){
                        tempj = 0;
                    }
                }

                if(flag){
                    break;
                }
            }

            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
