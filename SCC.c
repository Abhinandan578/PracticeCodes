#include<stdio.h>
#include<stdbool.h>
bool directed,weighted;
int time=0;
void SCCUtil(int i,int mat[][100],int v,char col[],int start[],int finish[])
{
	int j;
	time++;
	start[i]=time;
	col[i]='G';
	for(j=1;j<=v;j++)
	{
		if(mat[i][j]!=0)
		{
			if(col[j]=='W')
				SCCUtil(j,mat,v,col,start,finish);
		}
	}
	time++;
	finish[i]=time;
	col[i]='B';
}
void SCCTranspose(int i,int mat[][100],int v,char col[])
{
	int j;
	col[i]='G';
	printf("%d ",i);
	for(j=1;j<=v;j++)
	{
		if(mat[i][j]!=0)
		{
			if(col[j]=='W')
				SCCTranspose(j,mat,v,col);
		}
	}
	col[i]='B';
}
void SCC(int mat[][100],int v,char col[],int start[],int finish[])
{
	for(int i=1;i<=v;i++)
	{
		if(col[i]=='W')
			SCCUtil(i,mat,v,col,start,finish);
	}
	int index[2*v+1]={0};
	for (int i = 1; i <=v;++i)
	{
		index[finish[i]]=i;
		col[i]='W';
	}
	int transpose[100][100];
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			transpose[i][j]=mat[j][i];
		}
	}
	for(int i=2*v;i>=1;i--)
	{
		if(index[i]!=0&&col[index[i]]=='W')
		{
			SCCTranspose(index[i],transpose,v,col);
			printf("\n");
		}
	}
}
int main()
{
	int v,e,i,j,a,b,w;
	char col[100];
	int start[100];
	int finish[100];
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	char ch;
	int mat[100][100]={0};
	printf("Enter T(True) or F(False) whether graph is directed or Not\n");
	scanf("%c",&ch);
	if(ch=='T')
		directed=true;
	else
	{
		directed=false;
	}
	printf("Enter T(True) or F(False) whether graph is weighted or Not\n");
	scanf(" %c",&ch);
	if(ch=='T')
		weighted=true;
	else
		weighted=false;
	printf("Enter the number of vertice and edges\n");
	scanf("%d%d",&v,&e);
	printf("Enter each edge starting and ending vertice in graph\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		if(weighted)
		{
			printf("Enter the Weight for edge(%d,%d)\n",a,b);
			scanf("%d",&w);
			mat[a][b]=w;
			if(directed==false)
				mat[b][a]=w;
		}
		else
		{
			mat[a][b]=1;
			if(directed==false)
				mat[b][a]=1;
		}
	}
	printf("The Strongly connected components in graph are\n");
	SCC(mat,v,col,start,finish);


}