#include<stdio.h>
#include<stdbool.h>
#include<stdbool.h>
bool directed,weighted;
int front=1,rear=0;
int arr[10000];
void Enque(int x)
{
	rear++;
	arr[rear]=x;
}
int Deque()
{
	if(front>rear)
		return -1;
	int ans=arr[front++];
	return ans;
}
bool peek()
{
	if(front>rear)
		return false;
	return true;
}
void BFSTraversal(int mat[][100],int v,char col[])
{
	Enque(1);
	col[1]='G';
	int top;
	while(peek())
	{
		top=Deque();
		printf("%d ",top);
		for (int i = 1;i<=v;++i)
		{
			if(mat[top][i]==1)
			{
				if(col[i]=='W')
				{
					col[i]='G';
					Enque(i);
				}
			}
		}
		col[top]='B';
	}
}
void TopologicalSortUtil(int i,int mat[][100],int v,char col[])
{
	int j;
	col[i]='G';
	for(j=1;j<=v;j++)
	{
		if(mat[i][j]!=0)
		{
			if(col[j]=='W')
				TopologicalSortUtil(j,mat,v,col);
		}
	}
	col[i]='B';
	printf("%d ",i);
}
void TopologicalSort(int mat[][100],int v,char col[])
{
	for(int i=1;i<=v;i++)
	{
		if(col[i]=='W')
			TopologicalSortUtil(i,mat,v,col);
	}
}
void DFSTraversalUtil(int i,int mat[][100],int v,char col[])
{
	int j;
	col[i]='G';
	printf("%d ",i);
	for(j=1;j<=v;j++)
	{
		if(mat[i][j]!=0)
		{
			if(col[j]=='W')
				DFSTraversalUtil(j,mat,v,col);
		}
	}
	col[i]='B';
}
void DFSTraversal(int mat[][100],int v,char col[])
{
	for(int i=1;i<=v;i++)
	{
		if(col[i]=='W')
			DFSTraversalUtil(i,mat,v,col);
	}
}
int main()
{
	int v,e,i,j,a,b,w;
	char col[100];
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
	printf("The DFS Traversal of graph is\n");
	DFSTraversal(mat,v,col);
	printf("\n");
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	printf("The Topological Sorting of given graph is\n");
	TopologicalSort(mat,v,col);
	printf("\n");
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	printf("The BFS Traversal of given graph is\n");
	BFSTraversal(mat,v,col);

}