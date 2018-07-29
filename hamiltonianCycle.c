#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool safe(int i,int k,int conn[],int mat[][100],int n)
{
	int j;
	if(k==0)
		return true;
	for(j=0;j<k-1;j++)
		if(conn[j]==i)
			return false;
	if(k>=1 && mat[conn[k-1]][i]==0)
		return false;
	else
		return true;

}
bool HamiltonianCycle(int k,int n,int mat[100][100],int conn[100])
{
	int j;
	if(k==n&&mat[conn[k-1]][conn[0]]==1)
	{
		printf("Solution : \n");
		for (j = 0; j < n; ++j)
		{
			printf("%d ",conn[j] );
		}
		printf("\n");
		return true;
	}
	else if(k==n)
	{
		// printf("No cycle\n");
		return false;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(safe(i,k,conn,mat,n))
		{
			conn[k]=i;
			if(HamiltonianCycle(k+1,n,mat,conn))
			{
				return true;
			}
			else
			{
				conn[k]=-1;
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
	int conn[100];
	int mat[100][100];
	for (i = 0; i < n; ++i)
	{
		conn[i]=-1;
		for (j = 0; j < n; ++j)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	if(!HamiltonianCycle(0,n,mat,conn))
	{
		printf("No Cycle is possible\n");
	}

}