#include<stdio.h>
bool safe(int col,int nodeNo,int color[],int mat[][100])
{
	int i;
	for(i=0;i<nodeNo;i++)
	{
		if(mat[nodeNo][i]==1)
		{
			if(col==color[i])
				return false;
		}
	}
	return true;
}
bool graphColor(int mat[][100],int m,int k,int n,int color[],int *check)
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
		*check=1;
		return true;
	}
	int i;

	for(i=1;i<=m;i++)
	{
		if(safe(i,k,color,mat))
		{
			color[k]=i;
			if(!graphColor(mat,m,k+1,n,color,check))
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
	int check=0;
	for(m=1;m<=n;m++)
	{
		graphColor(mat,m,0,n,color,&check);
		if(check==1)
		{
			printf("Minimum %d colors needed to Color the Graph\n",m);
			break;
		}
	}

}