#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MAX 10001

vector<int>matrix[MAX];
stack<int>myStack;
bool visited[MAX];
void dfs(int n, int src)
{
    myStack.push(src);
    visited[src]=true;
    cout<<"Visit node in this sequence: "<<src<<" ";
    while(!myStack.empty())
    {
        int u = myStack.top(); myStack.pop();
        for(int i=0; i<matrix[u].size(); i++)
        {
            int v = matrix[u][i];
            if(!visited[v])
            {
                myStack.push(v);
                visited[v] = true;
                cout <<v<<" ";
            }
        }
    }
}
int main()
{
    //freopen("bfs1.txt", "r", stdin);
    int node, edge;
    cin>>node>>edge;
    while(edge--)
    {
        int x, y;
        cin>>x>>y;
        matrix[x].pb(y);
        matrix[y].pb(x);
    }
    int source;
    cin>>source;
    dfs(node, source);
    return 0;
}
