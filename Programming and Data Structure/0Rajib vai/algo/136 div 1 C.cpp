#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[100005],b[100005],c=0;
  bool flag=true;
  cin>>n;
  for(int i=0;i<n;i++) {cin>>a[i]; b[i]=a[i];}
  sort(a,a+n);
  for(int i=0;i<n;i++){
     if(b[i]!=a[i]) c++;
     if(c>2){
       flag=false;
     }
  }
  puts(flag? "YES": "NO");
}
