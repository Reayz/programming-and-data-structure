#include <bits/stdc++.h>
using namespace std;

#define N 1024

int tree[N][N];

struct treeNode {
    int par; // parent of this node
    int depth; // Depth of this node
    int size; // Size of subtree rooted with this node
    int pos_segbase; // Position in Segment tree base
    int chain;
}node[N];

struct Edge {
    int weight; // Weight of Edge
    int deeper_end; // Deeper End
}edge[N];

struct segmentTree{
    int base_array[N], tree[6*N];
}s;

void addEdge(int e, int u, int v, int w){
    tree[u - 1][v - 1] = e - 1;
    tree[v - 1][u - 1] = e - 1;
    edge[e - 1].weight = w;
}

void dfs(int curr, int prev, int dep, int n){
    node[curr].par = prev;
    node[curr].depth = depth;
    node[curr].size = 1;

    for(int j = 0;j < n; ++j){
        if(j != curr && j != node[curr].par && tree[curr][j] != -1){
            edge[tree[curr][j] ].deeper_end = j;
            dfs(j, curr, dep + 1, n);
            node[curr].size += node[j].size();
        }
    }
}

void hld(int curr_node, int id, int *edge_counted, int *curr_chain, int n, int chain_heads[]){
    if(chain_heads[*curr_chain] == -1){
        chain_heads[*curr_chain] = curr_node;
    }
    node[curr_node].chain = *curr_chain;
    node[curr_node].pos_segbase = *edge_counted;
    s.base_array[(*edge_counted)++] = edge[].weight;
}

int main(){
    memset(tree, -1, sizeof tree);

    int n = 11;

    /* arguments in order: Edge ID, node u, node v, weight w*/
    addEdge(1, 1, 2, 13);
    addEdge(2, 1, 3, 9);
    addEdge(3, 1, 4, 23);
    addEdge(4, 2, 5, 4);
    addEdge(5, 2, 6, 25);
    addEdge(6, 3, 7, 29);
    addEdge(7, 6, 8, 5);
    addEdge(8, 7, 9, 30);
    addEdge(9, 8, 10, 1);
    addEdge(10, 8, 11, 6);

    int root = 0, parent_of_root = -1, depth_of_root = 0;

    //a DFS on the tree to set up
    // arrays for parent, depth, subtree size for every node
    // deeper end of every edge

    dfs(root, parent_of_root, depth_of_root, n);

    int chain_heads[N];
    // we have initialized no chain heads
    memset(chain_heads, -1, sizeof chain_heads);

    //Stores number of edges for construction of Segment tree
    int edge_counted = 0;

    // we start with filing 0th chain
    int curr_chain = 0;

    // HLD of tree
    hld(root, n - 1, &edge_counted, &curr_chain, n, chain_heads);
}
