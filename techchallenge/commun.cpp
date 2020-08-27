#include <bits/stdc++.h>
using namespace std;

int M[1010][1010],backup[1010][1010],ROW,COL,minVal;
bool visited[1010][1010];
vector< pair<int,int> > groups[1010];

int isSafe(int row, int col)
{
    return (row >= 0) && (row <= ROW) &&
           (col >= 0) && (col <= COL) &&
           (M[row][col] < 0 && !visited[row][col]);
}
void DFS(int row, int col,int counts)
{
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    visited[row][col] = true;

    for (int k = 0; k < 8; ++k)
        if (isSafe(row + rowNbr[k], col + colNbr[k]) ){
            groups[counts].push_back(make_pair(row+rowNbr[k],col+colNbr[k]));
            DFS(row + rowNbr[k], col + colNbr[k],counts);
        }
}

int countIslands()
{
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] < 0 && !visited[i][j])
            {
                groups[count].push_back(make_pair(i,j));
                DFS(i, j,count);
                ++count;
            }

    return count;
}

int isSafe1(int row, int col)
{
    return (row >= 0) && (row <= ROW) &&
           (col >= 0) && (col <= COL) &&
           (!visited[row][col]);
}

stack< pair<int,int> > finalPath;

void distance(int x1,int y1,int x2,int y2, int dist,stack< pair<int,int> > path){
    if(x1 == x2 && y1 == y2 && dist != 0){
        if(dist < minVal)
            finalPath = path;
        minVal = min(dist,minVal);
        return;
    }
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    visited[x1][y1] = true;

    for (int k = 0; k < 8; ++k)
        if (isSafe1(x1 + rowNbr[k], y1 + colNbr[k]) ){
            path.push(make_pair(x1 + rowNbr[k], y1 + colNbr[k]));
            distance(x1 + rowNbr[k], y1 + colNbr[k],x2,y2,dist+(M[x1+rowNbr[k]][y1+colNbr[k]] > 0 ? M[x1+rowNbr[k]][y1+colNbr[k]] : 0),path);
            path.pop();
            visited[x1+rowNbr[k]][y1+colNbr[k]] = false;
        }
}
int main(){
    string s;
    cin>>s;

    bool neg = false,flag = true;

    vector<int> vec;

    for(int i = 0; i < s.length(); i++){
        while(i < s.length() && s[i] != '#'){
            if(s[i] == '-'){
                neg = true;
            }else{
                int val = 0,p = 0;
                string value = "";
                while(i < s.length() && s[i] != '@' && s[i] != '#'){
                    value += s[i];
                    i++;
                }
                for(int j = value.length()-1; j >= 0; j--){
                    val += ((value[j]-'0')*pow(10,p));
                    p++;
                }
                if(i < s.length()){
                    if(flag && s[i] == '@')
                        COL++;
                    else if(s[i] == '#'){
                        ROW++;
                        flag = false;
                    }
                }
                if(neg){
                    vec.push_back(-val);
                    neg = false;
                }else
                    vec.push_back(val);
            }
            i++;
        }
    }
    vec.clear();
    COL++;
    ROW++;
    int k = 0,counts = 0;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            M[i][j] = vec[k++];
            backup[i][j] = M[i][j];
            if(M[i][j] == -1)
                counts++;
        }
    }
    int val = countIslands();
    if(val == 1 || counts == 0){
        cout<<"0"<<endl;
    }else{
        int totalCost = 0,ans = INT_MAX;
        for(int i = 0;i < val; i++){
            for(int j = i + 1; j < val; j++){
                minVal = INT_MAX;
                for(int i1 = 0; i1 < groups[i].size(); i1++){
                    for(int j1 = 0; j1 < groups[j].size(); j1++){
                        memset(visited,0,sizeof(visited));
                        stack<pair<int,int> > path;
                        path.push(make_pair(groups[i][i1].first,groups[i][i1].second));
                        distance(groups[i][i1].first,groups[i][i1].second,groups[j][j1].first,groups[j][j1].second,0,path);
                    }
                }
                if(minVal != INT_MAX)
                    totalCost += minVal;

                while(!finalPath.empty()){
                    pair<int,int> p = finalPath.top();
                    finalPath.pop();
                    M[p.first][p.second] = -1;
                }

                int countOfGroups = countIslands();
                if(countOfGroups == 1){
                    ans = min(ans,totalCost);
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }

        cout<<ans<<endl;
    }
}
