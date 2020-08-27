#include <bits/stdc++.h>

using namespace std;

map<int,string> n;
int spend[51][51];

struct node{
    int totalCost;
    string s;
};

vector< pair<string,int> > results;

void printAllPaths(int s,int d, bool visited[], int path[], int &path_index, vector<int> adj[]){
    visited[s] = true;
    path[path_index] = s;
    path_index++;

    if(s == d){
        int totalcost = 0;
        string s = "";
        for(int i = 0; i < path_index-1; i++){
            s += n[path[i]]+" ";
            totalcost += spend[path[i]][path[i+1]];
        }
        s += n[path[path_index-1]];
        results.push_back(make_pair(s,totalcost));
    }else{
        for(int i = 0; i < adj[s].size(); i++){
            if(!visited[adj[s][i]]){
                printAllPaths(adj[s][i],d,visited,path,path_index,adj);
            }
        }
    }
    path_index--;
    visited[s] = false;
}
void paths(int s, int d, vector<int> adj[]){
    bool visited[51];
    int path[51];
    int path_index = 0;

    memset(visited,false,sizeof(visited));

    printAllPaths(s,d,visited,path,path_index, adj);
}

int checkString(string s, string d){
    vector<string> ss;
    vector<string> dd;

    string temp = "";

    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ')
            temp += s[i];
        else{
            ss.push_back(temp);
            temp = "";
        }
    }
    ss.push_back(temp);
    temp = "";
    for(int i = 0; i < d.length(); i++){
        if(d[i] != ' ')
            temp += d[i];
        else{
            dd.push_back(temp);
            temp = "";
        }
    }
    dd.push_back(temp);

    if(ss.size() != dd.size())
        return ss.size() > dd.size();
    for(int i = 0; i < ss.size(); i++){
        if(ss[i] == dd[i])
            continue;
        if(ss[i] > dd[i])
            return 1;
        return -1;
    }
    return 0;
}
int compare(const void *a, const void *b){
    struct node *s1 = (struct node*)a;
    struct node *s2 = (struct node*)b;

    if(s1->totalCost != s2->totalCost)
        return s1->totalCost > s2->totalCost;
    return checkString(s1->s, s2->s);
}

int main(){
    string source, destination;
    cin>>source;
    cin>>destination;

    char s[22],d[22];
    int cost;

    map<string,int> m;

    m[source] = 0;
    m[destination] = 50;
    n[0] = source;
    n[50] = destination;

    int k = 1;
    vector<int> adj[51];

    while(scanf("%s%s%d", &s, &d, &cost) != EOF){
        if(m.find(s) == m.end()){
            n[k] = s;
            m[s] = k++;
        }
        if(m.find(d) == m.end()){
            n[k] = d;
            m[d] = k++;
        }
        spend[m[s]][m[d]] = cost;
        adj[m[s]].push_back(m[d]);
    }
    paths(0,50,adj);

    if(results.size() == 0){
        cout<<"No Flights"<<endl;
    }else{
        struct node N[results.size()];

        for(int i = 0; i < results.size(); i++){
            cout<<results[i].first<<" "<<results[i].second<<endl;
            N[i].totalCost = results[i].second;
            N[i].s = results[i].first;
        }

        qsort(N,results.size(),sizeof(struct node), compare);

        for(int i = 0; i < results.size(); i++)
            cout<<N[i].s<<" "<<N[i].totalCost<<endl;
    }
}
