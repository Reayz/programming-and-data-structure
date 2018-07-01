/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30;
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define PI 3.1415926535897932384626433832795
using namespace std;
const int MAX = 100005;

int arr[MAX];
struct info
{
    int sum, prop;
}tree[4*MAX];
void build(int node, int b, int e)
{
    if(b==e){tree[node].sum=arr[b]; return;}
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
void update(int node, int b, int e, int i, int j, int Value)
{
    if(i>e or j<b) return;
    if(b>=i and e<=j)
    {
        tree[node].sum += ((e-b+1)*Value);
        tree[node].prop += Value;
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, Value);
    update(right, mid+1, e, i, j, Value);
    tree[node].sum = tree[left].sum + tree[right].sum + ((e-b+1)*tree[node].prop);
}
int query(int node, int b, int e, int i, int j, int carry=0)
{
    if(i>e or j<b) return 0;
    if(b>=i and e<=j) return tree[node].sum + ((e-b+1)*carry);
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    build(1, 1, n);

    cout<<query(1, 1, n, 3, 5)<<endl;       ///find sum 3 to 5
    update(1, 1, n, 3, 5, 7);           ///add 7, from 3 to 5 each
    cout<<query(1, 1, n, 3, 5)<<endl;       ///find sum 3 to 5
    return 0;
}
