#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long partition(long long a[],long long p,long long r)
{
    long long x,i,j;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return (i+1);
}

void quick_sort(long long a[],long long p,long long r)
{
    long long q;
    if(p<r)
    {
        q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
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
    quick_sort(array,1,num);
    printf("\nAfter sorting the list is : \n");
    for(i=1;i<=num;i++) printf("%lld ",array[i]);
    printf("\n");
    return 0;
}
