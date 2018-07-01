#include <bits/stdc++.h>
using namespace std;

const int NN = 105;

struct heap {
    int myarray[NN + 5];
    int n;
    heap(){
        clear();
    }
    void clear(){
        n = 0;
    }
    void insert(int k){
        if(n == NN){
            printf("Unable to Insert\n");
            return ;
        }
        n++;
        myarray[n] = k;
        int p = n;
        while(p > 1){
            int par = p / 2;
            if(myarray[par] > myarray[p]){
                swap(myarray[par],myarray[p]);
                p = par;
            }
            else break;
        }
    }
    int remove(){
        if(n == 0){
            printf("The heap is empty\n");
            return -1;
        }
        int k = myarray[1];
        myarray[1] = myarray[n];
        n--;
        int p = 1;
        while(2 * p <= n){
            int ch = 2 * p;
            if(2 * p + 1 <= n){
                if(myarray[ch] > myarray[ch + 1]) ch++;
            }
            if(myarray[p] > myarray[ch]){
                swap(myarray[p],myarray[ch]);
                p = ch;
            }
            else break;
        }
    }
    void print() {
        printf("Number of elements: %d\n", n);
        for(int i = 1; i <= n; i++ ) printf("%d ", myarray[i]);
        printf("\n");
    }
};

int main() {
    heap A;

    A.clear();

    A.insert(4);
    A.print();

    A.insert(5);
    A.print();

    A.insert(3);
    A.print();

    A.insert(2);
    A.print();

    A.insert(8);
    A.print();

    A.insert(9);
    A.print();

    A.insert(6);
    A.print();

    A.insert(1);
    A.print();

    printf("Deleting %d\n", A.remove());
    A.print();
    printf("Deleting %d\n", A.remove());
    A.print();
    printf("Deleting %d\n", A.remove());
    A.print();
    return 0;
}
