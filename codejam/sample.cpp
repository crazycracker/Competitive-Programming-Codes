#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        int arr[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }
        bool flag = true;

        for(int i = 0; i < m; i++){
            if(i == 0 || i == m-2){
                if(arr[0][i] > 2){
                    flag = false;
                    break;
                }
            }else{
                if(arr[0][i] > 3){
                    flag = false;
                    break;
                }
            }
        }

        if(!flag){
            cout<<"Unstable"<<endl;
        }else{
            for(int i = 0; i < m; i++){
                if(i == 0 || i == m-2){
                    if(arr[n-1][i] > 2){
                        flag = false;
                        break;
                    }
                }else{
                    if(arr[n-1][i] > 3){
                        flag = false;
                        break;
                    }
                }
            }

            if(!flag){
                cout<<"Unstable"<<endl;
            }else{
                for(int i = 1; i < n-1; i++){
                    for(int j = 1; j < m-1; j++){
                        if(arr[i][j] > 4){
                            flag = false;
                            break;
                        }
                    }
                }

                if(!flag){
                    cout<<"Unstable"<<endl;
                }else{
                    for(int i = 1; i < n-1; i++){
                        if(arr[i][0] > 3){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        cout<<"Unstable"<<endl;
                    }else{
                        for(int i = 1; i < n-1; i++){
                            if(arr[i][m-1] > 3){
                                flag = false;
                                break;
                            }
                        }

                        if(!flag){
                            cout<<"Unstable"<<endl;
                        }
                    }

                }
            }
        }

        if(flag)
            cout<<"Stable"<<endl;
    }
}
