#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        string m,n;
        cin>>m>>n;

        int m1,n1;
        m1 = m.length() + 1;
        n1 = n.length() + 1;

        vector<pair<int,int> > vec;
        int q,a,b,maxx=0;
        scanf("%d", &q);

        for(int i = 0; i < q; i++){
            scanf("%d%d", &a,&b);
            vec.push_back(make_pair(a,b));
            maxx = max(a,maxx);
        }

        char arr[maxx+1][m1];
        memset(arr,'#',sizeof(arr));

        for(int i = 1; i <= m1; i++){
            if(m[i-1] == '0'){
                arr[0][i] = 'W';
                arr[1][i] = '1';
            }else{
                arr[0][i] = 'L';
            }
        }
        for(int i = 1; i <= maxx; i++){
            if(n[i-1] == '0'){
                arr[i][0] = 'W';
                arr[i][1] = '1';
            }else{
                arr[i][0] = 'L';
            }
        }

        for(int i = 1; i <= maxx; i++){
            for(int j = 1; j < m1; j++){
                if(arr[i][j] != '#')
                    continue;
                if(arr[i][j-1] == 'L' && arr[i-1][j] == 'L'){
                    arr[i][j] = '2';
                }else if(arr[i][j-1] == '1' && arr[i-1][j] == 'L' || arr[i][j-1] == 'L' && arr[i-1][j] == '1'){
                    arr[i][j] = '2';
                }else if(arr[i][j-1] == '2' && arr[i-1][j] == 'L' || arr[i][j-1] == 'L' && arr[i-1][j] == '2'){
                    arr[i][j] = '1';
                }else if(arr[i][j-1] == '1' && arr[i-1][j] == '1'){
                    arr[i][j] = '2';
                }else if(arr[i][j-1] == '2' && arr[i-1][j] == '2'){
                    arr[i][j] = '1';
                }else if(arr[i][j-1] == '1' && arr[i-1][j] == '2' || arr[i][j-1] == '2' && arr[i-1][j] == '1'){
                    arr[i][j] = '1';
                }
            }
        }

        string str;

        for(int i = 0; i < q; i++){
            if(arr[vec[i].first][vec[i].second] == '1')
                str += '1';
            else
                str += '0';
        }
        cout<<str<<endl;
    }
}
