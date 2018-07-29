#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool directed,weighted;
typedef struct Edge
{
	int st;
	int end;
	int wt;
}Edge;
typedef struct Set
{
	struct Set* parent;
	int rank;
	int name;
}Set;
Set* MakeSet(int c)
{
	Set* x=(Set *)malloc(sizeof(Set));
	x->name=c;
	x->parent=x;
	x->rank=0; 
	return x;
}
Set* FindSet(Set* x)
{
	if(x->parent!=x)
		x->parent=FindSet(x->parent);
	return x->parent;
}
void Link(Set* x,Set* y)
{
	if(x->rank>y->rank)
		y->parent=x;
	else
		x->parent=y;
	if(x->rank==y->rank)
		y->rank++;
}
void Union(Set* x,Set* y)
{
	Link(FindSet(x),FindSet(y));
}
void swap(Edge& a,Edge& b)
{
	Edge temp;
	temp=a;
	a=b;
	b=temp;
}
void heapify(Edge arr[],int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	int minimum = i;
	if(left<=n&&arr[minimum].wt>arr[left].wt)
		minimum=left;
	if(right<=n&&arr[minimum].wt>arr[right].wt)
		minimum=right;
	if(minimum!=i)
	{
		swap(arr[minimum],arr[i]);
		heapify(arr,minimum,n);
	}
}
Edge ExtractMin(Edge arr[],int& n)
{
	Edge ans=arr[1];
	swap(arr[1],arr[n]);
	n--;
	heapify(arr,1,n);
	return ans;
}
void buildHeap(Edge arr[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		heapify(arr,i,n);
	}
}
void MSTKruskal(Edge arr[],int v,int e)
{
	Set* set[v];
	Edge ans[v];
	for (int i = 1; i<=v; ++i)
	{
		set[i]=MakeSet(i);
	}
	buildHeap(arr,e);
	int k=e;
	int count=0;
	for(int i=0;i<e;i++)
	{
		Edge a=ExtractMin(arr,k);
		if(FindSet(set[a.st])!=FindSet(set[a.end]))
		{
			ans[count++]=a;
			Union(set[a.st],set[a.end]);
		}
	}
	for(int i=0;i<count;i++)
	{
		printf("Start is %d and End is %d and Weight is %d \n",ans[i].st,ans[i].end,ans[i].wt);
	}


	
}
int main()
{
	int v,e,i,j,a,b,w;
	printf("Enter the number of vertice and edge\n");
	scanf("%d%d",&v,&e);
	Edge edge[e+1];
	printf("Enter each edge starting and ending vertice in graph and then its Weight\n");
	for(i=1;i<=e;i++)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&w);
		edge[i].st=a;
		edge[i].end=b;
		edge[i].wt=w;
	}
	printf("Kruskal MST is \n");
	MSTKruskal(edge,v,e);

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