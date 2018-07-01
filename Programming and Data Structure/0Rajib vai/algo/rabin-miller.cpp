#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

bool miller(LL p,LL iter)
{
    if(p<2) return false;
    if(p!=2 and p%2==0) return false;
    LL s=p-1;
    while(s%2==0) s/=2;
    for(LL i=0;i<iter;i++)
    {
        LL a=rand()%(p-1)+1,temp=s;
        LL mod=modulo(a,temp,p);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL num,iter=5;
    cout<<"Enter your number : ";
    cin>>num;
    if(miller(num,iter)) cout<<"It is a prime number\n";
    else cout<<"It is not a prime number\n";
    return 0;
}
