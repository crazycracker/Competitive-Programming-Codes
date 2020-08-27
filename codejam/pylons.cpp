#include <bits/stdc++.h>

using namespace std;

bool grid[1000][1000];
int r,c;
int xx, yy;
stack< pair<int,int> > finalPath;
bool done;

bool possible(int x, int y, int x1, int y1){
    if(x + x1 >= 1 && x + x1 <= r && y + y1 >= 1 && y + y1 <= c){
        if(!grid[x+x1][y+y1]){
            return true;
        }
    }

    return false;
}
void findAnswer(int x, int y, int cnt, stack< pair<int,int> > path){
    if(cnt == r*c && (x == xx || y == yy || (x - y == xx - yy) || (x + y == xx + yy))){
        finalPath = path;
        done = true;
        return;
    }

    for(int i = 1 - r; i < r; i++){
        for(int j = 1 - c; j < c; j++){
            int x1 = x + i;
            int y1 = y + j;

            if(!(x == x1 || y == y1 || (abs(x - x1) == abs(y - y1)))){
                if(possible(x, y, i, j)){
                    grid[x1][y1] = true;
                    path.push(make_pair(x1,y1));
                    findAnswer(x1, y1, cnt + 1, path);
                    if(done)
                        return;
                    path.pop();
                    grid[x1][y1] = false;
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;

    for(int t1 = 1; t1 <= t; t1++){
        cin>>r>>c;
        bool flag = false;

        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                memset(grid, false, sizeof(grid));
                stack< pair<int,int> > path;
                xx = i;
                yy = j;
                grid[xx][yy] = true;
                path.push(make_pair(i,j));
                findAnswer(i,j,1,path);
                if(done){
                    if(finalPath.empty())
                        continue;
                    flag = true;
                    cout<<"Case #"<<t1<<": POSSIBLE"<<endl;
                    while(!finalPath.empty()){
                        pair<int,int> val = finalPath.top();
                        cout<<val.first<<" "<<val.second<<endl;
                        finalPath.pop();
                    }
                    /*for(int k = 0; k < finalPath.size(); k++){
                        cout<<finalPath[k].first<<" "<<finalPath[k].second<<endl;
                    }*/
                    break;
                }
            }
            if(flag)
                break;
        }

        if(!flag){
            cout<<"Case #"<<t1<<": IMPOSSIBLE"<<endl;
        }
    }

    return 0;
}
