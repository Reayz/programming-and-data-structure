#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const long long infinity=10000000000LL;

void merge(long long a[],long long p,long long q,long long r)
{
    long long n1,n2,L[101],R[101],i,j,k;
    n1=q-p+1;
    n2=r-q;
    for(i=1;i<=n1;i++) L[i]=a[p+i-1];
    for(j=1;j<=n2;j++) R[j]=a[q+j];
    L[n1+1]=infinity;
    R[n2+1]=infinity;
    i=1,j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }
}

void merge_sort(long long a[],long long p,long long r)
{
    long long q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    long long num,array[101],i;
    printf("How many number you have : ");
    scanf("%lld",&num);
    printf("\nEnter your number : \n");
    for(i=1;i<=num;i++)
    {
        scanf("%lld",&array[i]);
    }
    merge_sort(array,1,num);
    printf("\nAfter sorting the list is : \n");
    for(i=1;i<=num;i++) printf("%lld ",array[i]);
    printf("\n");
    return 0;
}
