#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long array[101];

int main()
{
    long long num,i,j,key;
    printf("How many number you have : ");
    scanf("%lld",&num);
    printf("\nEnter your number : \n");
    for(i=1;i<=num;i++)
    {
        scanf("%lld",&array[i]);
    }
    for(j=2;j<=num;j++)
    {
        key=array[j];
        i=j-1;
        while(i>0 && array[i]>key)
        {
            array[i+1]=array[i];
            i=i-1;
            array[i+1]=key;
        }
    }
    printf("\nAfter sorting the list is : \n");
    for(i=1;i<=num;i++)
    {
        printf("%lld ",array[i]);
    }
    printf("\n");
    return 0;
}
