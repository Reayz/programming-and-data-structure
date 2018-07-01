#include<bits/stdc++.h>
using namespace std;

vector<int>Graph[105];
int visit[105];
int dist[105];
int back[105];
int timer;
int art[105];
int root;
int degreeOfroot;

void findArt(int u){
    visit[u] = 1;
    timer++;
    back[u] = dist[u] = timer;
    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        if(!visit[v]){
            findArt(v);
            if(u == root) degreeOfroot++;
            if(degreeOfroot >= 2) cout << u << " "; // art[u] = 1;
            back[u] = min(back[u],back[v]);
            if(back[v] >= dist[u] && u != root) cout << u << " "; // art[u] = 1;
        }else{
            back[u] = min(back[u],dist[v]);
        }
    }
}

int main(){
    int n,u,v;
    cin >> n;
    while(cin >> u >> v){
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    root = 1;
    findArt(root);
    cout << '\n';
    for(int i=1;i<=n;i++) cout << i << " " << dist[i] << " " << back[i] << '\n';
    return 0;
}
