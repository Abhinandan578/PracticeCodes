#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define t 3 
typedef struct node
{
	int keys[2*t];
	node* child[(2*t)+1];
	node* parent=NULL;
	bool isLeaf;
	int N;
} Node;
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int* arr,int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<=high;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(&arr[++i],&arr[j]);
		}
	}
	return i;
}
void sortKeys(int arr[],int low,int high)
{
	if(low>high)
		return;
	int index =partition(arr,low,high);
	sortKeys(arr,low,index-1);
	sortKeys(arr,index+1,high);
}
Node* ReadBTree(Node* temp,int number,int height)
{
	temp=(Node *)malloc(sizeof(Node));
	int n;
	if(number==0)
	{
		printf("Enter the number of keys the Root have\n");
	}
	else if(number<0)
	{
		printf("Enter the number of keys in the node on the right of %d\n",(-1*number));
	}
	else
	{
		printf("Enter the number of keys in the node on the left of %d\n",number);
	}
	scanf("%d",&n);
	if(n>(2*t)-1||(n<t-1&&number!=0))
	{
		printf("Not Possible\n");
		return ReadBTree(temp,number,height);
	}
	temp->N=n;
	printf("Enter the values of keys in this node\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&(temp->keys[i]));
	}
	sortKeys(temp->keys,1,n);
	if(height==1)
	{
		temp->isLeaf=true;
	}
	else
	{
		temp->isLeaf=false;
		for(int i=1;i<=n+1;i++)
		{
			if(i<n+1)
			{
				temp->child[i]=ReadBTree(temp->child[i],temp->keys[i],height-1);
			}
			else
			{
				temp->child[i]=ReadBTree(temp->child[i],(-1*temp->keys[i-1]),height-1);	
			}
			temp->child[i]->parent=temp;
		}
	}
	return temp;
}
void traversal(Node* temp,int number)
{
	int i;
	if(number==0)
	{
		printf("The root node is \n");
		for(i=1;i<=temp->N;i++)
		{
			printf("%d ",temp->keys[i]);
		}
		printf("\n");
		for (i = 1; i<=(temp->N+1)&&temp->isLeaf==false; ++i)
		{
			if(i<(temp->N)+1)
			{
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				traversal(temp->child[i],(-1*temp->keys[i-1]));
			}
		}
	}
	else if(number<0)
	{
		printf("The keys on the right of %d is\n",(-1*number));
		for(i=1;i<=temp->N;i++)
		{
			printf("%d ",temp->keys[i]);
		}
		printf("\n");
		for (i=1;(i<=temp->N+1&&temp->isLeaf==false);++i)
		{
			if(i<(temp->N)+1)
			{
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				traversal(temp->child[i],(-1*temp->keys[i-1]));
			}
		}
	}
	else
	{
		printf("The keys on the left of %d is\n",number);
		for(i=1;i<=temp->N;i++)
		{
			printf("%d ",temp->keys[i]);
		}
		printf("\n");
		for (i = 1;(i<=(temp->N)+1)&&(temp->isLeaf==false);++i)
		{
			if(i<(temp->N)+1)
			{
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				traversal(temp->child[i],(-1*temp->keys[i-1]));
			}
		}
	}
}
void SplitChild(Node** x,int i)
{
	Node* z=(Node *)malloc(sizeof(Node));
	Node* y=(*x)->child[i];
	z->N=t-1;
	z->isLeaf=y->isLeaf;
	int j,k;
	for(j=1;j<=t-1;j++)
	{
		z->keys[j]=y->keys[j+t];
	}
	if(y->isLeaf==false)
	{
		for(j=1;j<=t;j++)
		{
			z->child[j]=y->child[j+t];
		}
	}
	y->N=t-1;
	for(j=(*x)->N;j>=i;j--)
	{
		(*x)->keys[j+1]=(*x)->keys[j];
	}
	(*x)->keys[i]=y->keys[t];
	for(j=(*x)->N+1;j>=i+1;j--)
	{
		(*x)->child[j+1]=(*x)->child[j];
	}
	(*x)->child[i+1]=z;
	(*x)->N++;
}
void InsertNonFull(Node** x,int k)
{
	int i=((*x)->N);
	if((*x)->isLeaf)
	{
		while(i>=1&&k<(*x)->keys[i])
		{
			(*x)->keys[i+1]=(*x)->keys[i];
			i--;
		}
		(*x)->keys[i+1]=k;
		(*x)->N++;
	}
	else
	{
		while(i>=1&&k<(*x)->keys[i])
			i--;
		i++;
		if((*x)->child[i]->N==2*t-1)
		{
			SplitChild(x,i);
			if(k>(*x)->keys[i])
				i=i+1;
		}
		InsertNonFull(&((*x)->child[i]),k);
	}
}
void Insert(Node** root,int k)
{
	if((*root)->N==(2*t)-1)
	{
		Node* s=(Node *)malloc(sizeof(Node));
		s->isLeaf=false;
		s->N=0;
		s->child[1]=(*root);
		root=&s;
		SplitChild(root,1);
		InsertNonFull(root,k);
		
	}
	else
	{
		InsertNonFull(root,k);
	}
}
int main()
{
	Node* root;
	int h,value;
	printf("Enter the height of B-Tree\n");
	scanf("%d",&h);
	bool check=false;
	root=ReadBTree(root,0,h);
	traversal(root,0);
	printf("Enter the value to be Inserted in the B-Tree\n");
	scanf("%d",&value);
	Insert(&root,value);
	traversal(root,0);
	return 0;
}