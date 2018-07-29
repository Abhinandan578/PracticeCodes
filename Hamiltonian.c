#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool safe(int i,int k,int mat[][100],int pos[])
{
	if(k==0)
		return true;
	for(int j=0;j<k;j++)
	{
		if(pos[j]==i)
			return false;
	}
	if(mat[pos[k-1]][i]==0)
			return false;
	return true;
}
bool Hamiltonian(int mat[][100],int n,int k,int pos[])
{
	if(k==n)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",pos[j]);
		}
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(safe(i,k,mat,pos))
		{
			pos[k]=i;
			if(Hamiltonian(mat,n,k+1,pos))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	printf("Enter the number of vertices in a graph\n");
	int n,i,j;
	scanf("%d",&n);
	printf("Enter the adjajency matrix\n");
	int pos[100];
	int mat[100][100];
	for (i = 0; i < n; ++i)
	{
		pos[i]=-1;
		for (j = 0; j < n; ++j)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Hamiltonian path is \n");
	Hamiltonian(mat,n,0,pos);
}