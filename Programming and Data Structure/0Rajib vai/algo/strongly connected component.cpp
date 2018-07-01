#include<bits/stdc++.h>
using namespace std;

stack<int>dfs_stack;
set<int>in_set;
int dfs_low[102];
int dfs_num[102];
int cou;

vector<int>adj[102];

void SCC(int u)
{
    dfs_low[u] = dfs_num[u] = cou++;
    dfs_stack.push(u); in_set.insert(u);
    for(int i=0;i<(int)adj[u].size();i++)
    {
        int v = adj[u][i];
        if(dfs_num[v] == -1) SCC(v);
        if(in_set.find(v) != in_set.end()) dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_num[u] == dfs_low[u])
    {
        cout << "SCC : ";
        while(!dfs_stack.empty() and dfs_stack.top() != u)
        {
            cout << dfs_stack.top() << " ";
            in_set.erase(dfs_stack.top());
            dfs_stack.pop();
        }
        cout << dfs_stack.top() << '\n';
        in_set.erase(dfs_stack.top());
        dfs_stack.pop();
    }
}

int main(){
    int node,edge;
    while(cin >> node >> edge)
    {
        for(int i=1;i<=edge;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        memset(dfs_num,-1,sizeof dfs_num);
        cou = 0;
        for(int i=1;i<=node;i++)
        {
            if(dfs_num[i] == -1) SCC(i);
        }
        for(int i=0;i<=node;i++) adj[i].clear();
        in_set.clear();
    }
    return 0;
}
/*
10 15
1 2
2 3
3 4
4 1
3 1
3 5
5 6
6 7
7 3
7 5
6 8
8 9
9 10
10 6
9 6
*/
