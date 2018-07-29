#include<stdio.h>
bool safe(int col,int nodeNo,int color[],int mat[][100])
{
	int i;
	for(i=0;i<nodeNo;i++)
	{
		if(mat[nodeNo][i]==1)//imp
		{
			if(col==color[i])
				return false;
		}
	}
	return true;
}
bool graphColor(int mat[][100],int m,int k,int n,int color[])
{
	if(k==n)
	{	
		printf("Color combination is \n");
		int i;
		for(i=0;i<n;i++)
		{
			printf("%d ",color[i]);
		}
		printf("\n");
		return true;
	}
	int i;

	for(i=1;i<=m;i++)
	{
		// printf("Checking for giving color %d to node %d \n",i,k);
		if(safe(i,k,color,mat))
		{
			// printf("Color %d  given to node %d \n",i,k);
			color[k]=i;
			if(graphColor(mat,m,k+1,n,color))
			{
				return true;
			}
			else
			{
				color[k]=0;
			}
		}
	}
	return false;
}
int main()
{
	printf("Enter the number of nodes in graph\n");
	int n,m;
	scanf("%d",&n);
	printf("Enter the adjajency matrix for the graph\n");
	int mat[100][100],i,j;
	int color[100];
	for(i=0;i<n;i++)
	{
		color[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(m=1;m<=n;m++)
	{
		if(graphColor(mat,m,0,n,color))
		{
			printf("Minimum %d colors needed to Color the Graph\n",m);
			break;
		}
	}

}