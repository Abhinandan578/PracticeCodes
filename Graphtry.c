#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool directed,weighted;
int front=1,rear=0;
int arr[1000];
int stack[1000];
int top=-1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	if(top==-1)
		return -1;
	return stack[top--];
}
bool see()
{
	if(top==-1)
		return false;
	return true;
}
void Enque(int x)
{
	rear++;
	arr[rear]=x;
	return;
}
int Deque()
{
	if(rear<front)
		return -1;
	int x=arr[front++];
	return x;
}
bool peak()
{
	if(front>rear)
		return false;
	else
		return true;
}
typedef struct adjListNode
{
	int dest;
	int wt;
	struct adjListNode* next;
}adjListNode;
typedef struct adjList
{
	adjListNode* head;
}adjList;
typedef struct Graph
{
	int V;
	adjList* arr;
}Graph;
Graph* createGraph(int V)
{
	Graph* g=(Graph *)malloc(sizeof(Graph));
	g->V=V;
	g->arr=(adjList*)malloc(sizeof(adjList)*V);
	for(int i=0;i<V;i++)
	{
		g->arr[i].head=NULL;
	}
	return g;
}
adjListNode* newNode(int dest,int wt)
{
	adjListNode* temp = (adjListNode*)malloc(sizeof(adjListNode));
	temp->next=NULL;
	temp->dest=dest;
	temp->wt=wt;
	return temp;
}
adjListNode* insertNode(adjListNode* head,int dest,int wt)
{
	adjListNode* temp = newNode(dest,wt);
	if(head==NULL)
		return temp;
	else
	{
		temp->next=head;
		head=temp;
	}
	return head;

}
void printGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct adjListNode* pCrawl = graph->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
void TopologicalSortUtil(int i,Graph* g,char* col)
{
	col[i]='G';
	adjListNode* head=g->arr[i].head;
	while(head)
	{
		if(col[head->dest]=='W')
		{
			TopologicalSortUtil(head->dest,g,col);
		}
		head=head->next;
	}
	col[i]='B';
	push(i);
}
void TopologicalSort(Graph* g,char* col)
{
	int v=g->V;
	for(int i=0;i<v;i++)
	{
		if(col[i]=='W')
		{
			TopologicalSortUtil(i,g,col);
		}
	}
	while(see())
	{
		int x=pop();
		printf("%d ",x);
	}
}
void DFSTraversalUtil(int i,Graph* g,char* col)
{
	col[i]='G';
	printf("%d ",i);
	adjListNode* head=g->arr[i].head;
	while(head)
	{
		if(col[head->dest]=='W')
		{
			DFSTraversalUtil(head->dest,g,col);
		}
		head=head->next;
	}
	col[i]='B';
}
void DFSTraversal(Graph* g,char* col)
{
	int v=g->V;
	for(int i=0;i<v;i++)
	{
		if(col[i]=='W')
		{
			DFSTraversalUtil(i,g,col);
		}
	}
}
void BFSTraversal(Graph* g,char * col)
{
	Enque(0);
	col[0]='G';
	while(peak())
	{
		int x=Deque();
		printf("%d ",x);
		adjListNode* head=g->arr[x].head;
		while(head)
		{
			if(col[head->dest]=='W')
			{
				col[head->dest]='G';
				Enque(head->dest);
			}
			head=head->next;
		}
		col[x]='B';

	}
}
int main()
{
	// printf("Enter the number of vertices and edges in graph\n");
	int v,e,i,j,a,b,w;
	char col[100];
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	char ch;
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
	Graph* g=createGraph(v);
	printf("Enter each edge starting and ending vertice in graph\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		if(weighted)
		{
			printf("Enter the Weight for edge(%d,%d)\n",a,b);
			scanf("%d",&w);
			g->arr[a].head=insertNode(g->arr[a].head,b,w);
			if(directed==false)
				g->arr[b].head=insertNode(g->arr[b].head,a,w);
		}
		else
		{
			g->arr[a].head=insertNode(g->arr[a].head,b,1);
			if(directed==false)
				g->arr[b].head=insertNode(g->arr[b].head,a,1);
		}
	}
	printGraph(g);
	printf("The DFS Traversal of graph is\n");
	DFSTraversal(g,col);
	printf("\n");
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	printf("The Topological Sorting of given graph is\n");
	TopologicalSort(g,col);
	printf("\n");
	for (i = 0; i <=100; ++i)
	{
		col[i]='W'; 
	}
	printf("The BFS Traversal of given graph is\n");
	BFSTraversal(g,col);
}