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
void MSTPrims(int mat[][100],int v,int e)
{
	Vertice** arr;
	arr=(Vertice **)malloc(sizeof(Vertice *) * (v+1));
	for(int i=1;i<=v;i++)
	{
		arr[i]=(Vertice *)malloc(sizeof(Vertice));
	}
	int ans[v+1];
	for (int i = 1; i<=v; ++i)
	{
		arr[i]->name=i;
		arr[i]->key=INT_MAX;
		arr[i]->parent=-1;
		arr[i]->mark=true;
	}
	arr[1]->key=0;
	buildHeap(arr,v);
	int k=v;
	int count=0;
	for(int i=1;i<=v;i++)
	{
		Vertice* a=ExtractMin(arr,&k);
		ans[count++]=a->name;
		a->mark=false;
		for(int j=1;j<=v;j++)
		{
			if(mat[a->name][arr[j]->name]>0)
			{
				if(arr[j]->mark==true&&arr[j]->key>mat[a->name][arr[j]->name])
				{
					arr[j]->key=mat[a->name][arr[j]->name];
					arr[j]->parent=a->name;
					percolateUp(arr,j);
				}
			}
		}

	}
	for(int i=0;i<count;i++)
	{
		printf("%d vertice traversed is %d\n",i+1,ans[i]);
	}


	
}
int main()
{
	int v,e,i,j,a,b,w;
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
		mat[b][a]=w;
	}
	printf("Prims MST is \n");
	MSTPrims(mat,v,e);

}
/*
1 2 4
1 8 8
2 3 8
2 8 11
8 9 7
3 9 2
8 7 1
9 7 6
3 6 4
3 4 7
7 6 2
4 6 14
4 5 9
5 6 10
 */