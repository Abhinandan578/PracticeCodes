// C++ program to rotate a matrix by 90 degrees
#include <bits/stdc++.h>
#define N 4
using namespace std;
 
void displayMatrix(int mat[N][N]);
 
// An Inplace function to rotate a N x N matrix
// by 90 degrees in anti-clockwise direction
void rotateMatrix(int mat[][N])
{
    bool flag[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            flag[i][j]=false;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(flag[i][j]==false)
            {
                int temp=mat[i][j];
                flag[i][j]=true;

                mat[i][j]=mat[j][N-1-i];
                flag[j][N-1-i]=true;

                mat[j][N-1-i]=mat[N-1-i][N-1-j];
                flag[N-1-i][N-1-j]=true;

                mat[N-1-i][N-1-j]=mat[N-1-j][i];
                flag[N-1-j][i]=true;

                mat[N-1-j][i]=temp;
            }
        }
    } 
}
 
// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
 
        printf("\n");
    }
    printf("\n");
}
 
 
/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
 
 
    // Tese Case 2
    /* int mat[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
     */
 
    // Tese Case 3
    /*int mat[N][N] = {
                    {1, 2},
                    {4, 5}
                };*/
 
    //displayMatrix(mat);
 
    rotateMatrix(mat);
 
    // Print rotated matrix
    displayMatrix(mat);
 
    return 0;
}