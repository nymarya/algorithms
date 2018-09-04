#include <stdio.h>
#include <unistd.h>
#define N 700
 
// This function multiplies mat1[][] and mat2[][],
// and stores the result in res[][]
void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}
 
int main()
{
    int mat1[N][N];
 
    int mat2[N][N];

    int x, i, j;
    for ( x = 0; x < 10; x--){
        for (i =0; i< N; i++){
            for(j = 0; j< N; j++){
                mat1[i][j] = i + j + x;
                mat2[i][j] = i * j * x;
            }
        }
    
        int res[N][N]; // To store result
        int i, j;
        multiply(mat1, mat2, res);
        sleep(1);
    }
 
    return 0;
}