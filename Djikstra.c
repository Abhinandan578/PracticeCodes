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
void swap(Vertice* a, Vertice* b) {
    Vertice temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Vertice** arr,int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	int minimum = i;
	if(left<=n&&arr[minimum]->key>arr[left]->key)
		minimum=left;
	if(right<=n&&arr[minimum]->key>arr[right]->key)
		minimum=right;
	if(minimum!=i)
	{
		swap(arr[minimum],arr[i]);
		heapify(arr,minimum,n);
	}
}
Vertice* ExtractMin(Vertice** arr,int* n)
{
	swap(arr[1],arr[*n]);
	(*n)--;
	heapify(arr,1,*n);
	return arr[(*n)+1];
}
void percolateUp(Vertice** arr,int k)
{
	int parent=k/2;
	while(parent>=1&&arr[parent]->key>arr[k]->key)
	{
		swap(arr[parent],arr[k]);
		k=parent;
		parent=k/2;
	}
}
void buildHeap(Vertice** arr,int n)
{
	for(int i=n/2;i>=1;i--)
	{
		heapify(arr,i,n);
	}
}
void Djikstra(int mat[][100],int v,int e,int src)
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
	buildHeap(arr,v);
	int k=v;
	for(int i=1;i<=v;i++)
	{
		Vertice* a=ExtractMin(arr,&k);
		a->mark=false;
		for(int j=1;j<=v;j++)
		{
			if(mat[a->name][arr[j]->name]>0)
			{
				if(arr[j]->mark==true&&arr[j]->key>(mat[a->name][arr[j]->name]+a->key))
				{
					arr[j]->key=mat[a->name][arr[j]->name]+
					a->key;
					arr[j]->parent=a->name;
					percolateUp(arr,j);
				}
			}
		}

	}
	for(int i=1;i<=v;i++)
	{
		printf("For vertice %d path from source is  %d\n",arr[i]->name,arr[i]->key);
	}


	
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
	int src;
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	printf("Djikstra paths from source vertex are \n");
	Djikstra(mat,v,e,src);

}
/*
6 8

1 2 15
2 6 2
1 6 20
2 3 11
6 3 7
3 4 1
5 4 9
6 5 2
 */