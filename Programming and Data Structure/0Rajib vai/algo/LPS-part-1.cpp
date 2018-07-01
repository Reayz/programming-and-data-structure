/* Rajib Chandra Paul
   CSE,4th Batch
   Comilla University

   longest palindrome substring
   Complexity : O(n * n)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;

char s[N];

int LPS(){
    int mx = 1,start = 0,len;
    len = strlen(s);

    int low, high;
    for(int i = 1;i < len; i++){

        // even length....
        low = i - 1; high = i;
        while(low >= 0 && high < len && s[low] == s[high]){
            if(high - low + 1 > mx){
                mx = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }

        //odd length
        low = i - 1; high = i + 1;
        while(low >= 0 && high < len && s[low] == s[high]){
            if(high - low + 1 > mx){
                mx = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }
    }

    return mx;
}

int main(){
    int test; scanf("%d",&test);
    while(test--){
        scanf("%s", s);
        printf("%d\n",LPS());
    }
    return 0;
}
