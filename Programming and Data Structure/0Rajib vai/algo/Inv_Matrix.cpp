#include <bits/stdc++.h>
using namespace std;

const int N = 50;

double inv_mat[N][N], mat[N][N], mi_mat[N][N];

double Determinant(double matrix[][N], int n){
    double det = 0;
    if(n == 1){
        return matrix[1][1];
    }else if(n == 2){
        return matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
    }else{
        for(int k = 1;k <= n; k++){
            //P(matrix, k, n);

            double temp[N][N];

            for(int i = 1;i <= n; i++){
                for(int j = 1;j <= n; j++){
                    temp[i][j]= matrix[i][j];
                }
            }

            for(int i = 1;i <= n; i++){
                for(int j = k;j < n; j++){
                    swap(temp[i][j], temp[i][j + 1]);
                }
            }

            for(int i = 1;i < n; i++){
                for(int j = 1;j <= n; j++){
                    swap(temp[i][j], temp[i + 1][j]);
                }
            }

            det += pow(-1 , (1 + k)) * matrix[1][k] * Determinant(temp , n - 1);
        }
    }

    return det;
}

void Minor(int matrix [][N], int n){
    if(n == 1){
        return
    }

}

int main(){
    int n; cin >> n;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n; j++){
            cin >> mat[i][j];
        }
    }

    //double det = Determinant(mat , n);
    Minor(mat , n);
    printf("%.10lf\n",det);

}

/*
4
3 0 2 -1
1 2 0 -2
4 0 6 -3
5 0 2 0
*/
