#include<bits/stdc++.h>
using namespace std;

int lps[1005];

void prefix_function(char *p)
{
    int m = strlen(p+1);
    lps[1] = 0;
    int q = 0;
    for(int k=2;k<=m;k++)
    {
        while(q > 0 and p[q+1] != p[k]) q = lps[q];
        if(p[q+1] == p[k]) q++;
        lps[k] = q;
    }
}

int KMP(char *t, char *p)
{
    int n = strlen(t+1);
    int m = strlen(p+1);
    int co = 0;
    int q = 0;
    for(int i=1;i<=n;i++)
    {
        while(q > 0 and t[i] != p[q+1]) q = lps[q];
        if(t[i] == p[q+1]) q++;
        if(q == m)
        {
            co++;
            q = lps[q];
        }
    }
    return co;
}
int main()
{
    int i,j,k,d;
    char s1[1005],s2[1005];
    while(scanf("%s%s",s1+1,s2+1) == 2)
    {
        prefix_function(s2);
        int ans = KMP(s1,s2);
        printf("Number of substrings matched = %d\n",ans);
    }
    return 0;
}
