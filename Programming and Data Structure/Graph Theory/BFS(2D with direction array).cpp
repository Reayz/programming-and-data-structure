
/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
#define MAX 10001

#define pii pair<int, int>
int MATRIX[MAX][MAX];
queue<pii>Q;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int des[MAX][MAX], vis[MAX][MAX];
int row, col;
void BFS(int sx, int sy)
{
    mem(vis,0);
    vis[sx][sy]=1;
    Q.push(pii(sx,sy));
    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int tx=top.first + fx[i];
            int ty=top.second + fy[i];
            if(tx>=0 and tx<row and ty>=0 and ty<col and MATRIX[tx][ty]!=-1 and vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                des[tx][ty]=des[top.first][top.second]+1;
                Q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    //freopen("BFS2.txt", "r", stdin);
    int node, edge;
    int x, y;
    cin>>node>>edge;
    row=col=node;
    while(edge--)
    {
        cin>>x>>y;
        MATRIX[x][y]=1;
    }
    BFS(1,1);
    return 0;
}
