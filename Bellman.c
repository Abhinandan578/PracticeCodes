#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
bool directed,weighted;
typedef struct Vertice
{
	int name;
	int key;
	int parent;
	bool mark;
}Vertice;
bool Bellman(int mat[][100],int v,int e,int src)
{
	Vertice** arr;
	arr=(Vertice **)malloc(sizeof(Vertice *) * (v+1));
	for(int i=1;i<=v;i++)
	{
		arr[i]=(Vertice *)malloc(sizeof(Vertice));
		arr[i]->name=i;
		arr[i]->key=INT_MAX;
		arr[i]->parent=-1;
		arr[i]->mark=true;
	}
	arr[src]->key=0;
	for(int i=1;i<v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			for(int k=1;k<=v;k++)
			{
				if(mat[j][k]>0&&arr[j]->key!=INT_MAX)
				{
					if(arr[k]->key>(arr[j]->key+mat[j][k]))
					{
						arr[k]->key=arr[j]->key+mat[j][k];
	
					}
				}
			}
		}
	}
	for(int j=1;j<=v;j++)
	{
		for(int k=1;k<=v;k++)
		{
			if(mat[j][k]>0)
			{
				if(arr[k]->key>arr[j]->key+mat[j][k])
				{
					return false;
				}
			}
		}
	}
	for(int i=1;i<=v;i++)
	{
		printf("For vertice %d path from source is  %d\n",arr[i]->name,arr[i]->key);
	}
	return true;
}
int main()
{
	int v,e,i,j,a,b,w;
	char ch;
	printf("Enter T(True) or F(False) whether graph is directed or Not\n");
	scanf("%c",&ch);
	if(ch=='T')
		directed=true;
	else
	{
		directed=false;
	}
	printf("Enter the number of vertice and Edges\n");
	scanf("%d%d",&v,&e);
	Vertice arr[v+1];
	int mat[100][100]={0};
	printf("Enter each Vertice starting and ending vertice in graph and then its Weight\n");
	for(i=1;i<=e;i++)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&w);
		mat[a][b]=w;
		if(directed==false)
			mat[b][a]=w;
	}
	printf("Matrix is\n");
	for(int j=1;j<=v;j++)
	{
		for(int k=1;k<=v;k++)
		{
			printf("%d ",mat[j][k]);
		}
		printf("\n");
	}
	int src;
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	printf("Bellman paths from source vertex are \n");
	if(!Bellman(mat,v,e,src))
	{
		printf("not possible due to negative Weight cycles present in graph\n");
	}

}