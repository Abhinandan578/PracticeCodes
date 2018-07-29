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
	if(temp==NULL)
	{
		printf("Empty B-Tree\n");
		return;
	}
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
			if(i< temp->N + 1)
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
Node* sortedInsert(Node temp[],int value)
{
	temp->N++;
	temp->keys[temp->N]=value;
	int j=(temp->N)-1;
	while(j>=1&&temp->keys[j]>value)
	{
		temp->keys[j+1]=temp->keys[j];
		if(temp->isLeaf==false)
		{
			temp->child[j+2]=temp->child[j+1];
		}
		j--;
	}
	temp->keys[j+1]=value;
	return temp;
}
void splitChild(Node** temp,int i,int value)
{	
	if((*temp)->N==((2*t)-1))
	{
		int index;
		if((*temp)->parent==NULL)
		{
			(*temp)->parent=(Node*)malloc(sizeof(Node));
			(*temp)->parent->N=0;
			(*temp)->parent->child[1]=(*temp);
			(*temp)->parent->child[2]=(Node*)malloc(sizeof(Node));
			(*temp)->parent->child[2]->isLeaf=(*temp)->isLeaf;
			index=1;
		}
		else
		{
			for(int j=1;j<=(*temp)->N;j++)
			{
				if((*temp)->parent->child[j]==(*temp))
				{
					index=j;
				}
				break;
			}
		}
		splitChild(&((*temp)->parent),index,(*temp)->child[i]->keys[t]);
	}
	else
	{
		(*temp)=sortedInsert((*temp),(*temp)->child[i]->keys[t]);
	}
	if((*temp)->isLeaf==false)
	{
		(*temp)->child[i+1]=(Node*)malloc(sizeof(Node));
		(*temp)->child[i+1]->isLeaf=(*temp)->child[i]->isLeaf;
		(*temp)->child[i]->N=t-1;
		(*temp)->child[i+1]->N=t-1;
		int j;
		for(j=t+1;j<=2*t;j++)
		{
			if(j<2*t)
			{
				(*temp)->child[i+1]->keys[j-t]=(*temp)->child[i]->keys[j];
			}
			if((*temp)->child[i]->isLeaf==false)
			{	
				(*temp)->child[i+1]->child[j-t]=(*temp)->child[i]->child[j];
			}
		}
	}
	if(value<(*temp)->child[i]->keys[t])
	{
		(*temp)->child[i]=sortedInsert((*temp)->child[i],value);
	}
	else
	{
		(*temp)->child[i+1]=sortedInsert((*temp)->child[i+1],value);	
	}
}
void Insert(Node** temp,int value,int k,int height)
{
	int i;
	if(height==1)
	{		
		if((*temp)&&(*temp)->N==((2*t)-1))
		{		
			if((*temp)->parent==NULL)
			{
				(*temp)->parent=(Node*)malloc(sizeof(Node));
				(*temp)->parent->N=0;
				(*temp)->parent->child[k]=(*temp);
				(*temp)->parent->child[k+1]=(Node*)malloc(sizeof(Node));
				(*temp)->parent->child[k+1]->isLeaf=true;
			}
			splitChild(&((*temp)->parent),k,value);
		}
		else
		{
			if(!(*temp))
			{	
				(*temp)=(Node*)malloc(sizeof(Node));
				(*temp)->isLeaf=true;
			}
			(*temp)=sortedInsert((*temp),value);
		}
	}
	else
	{
		i=(*temp)->N;
		while(i>=1&&value<(*temp)->keys[i])
			i--;
		i++;
		Insert(&((*temp)->child[i]),value,i,height-1);
	}
}
int main()
{	
	int check=0;
	Node* root=NULL;
	while(check==0)
	{
		int n;
		int h,value;
		printf("Enter 1 to create a new BTree\nEnter 2 to insert a node in BTree\nEnter 3 to traverse the tree\nEnter 4 to Quit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:			
					printf("Enter the height of B-Tree\n");
					scanf("%d",&h);
					root=NULL;
					root=ReadBTree(root,0,h);
					break;
			case 2:
					printf("Enter the value to be Inserted in the B-Tree\n");
					scanf("%d",&value);
					if(root==NULL)
						h=1;
					Insert(&root,value,1,h);
					if(root->parent!=NULL)
						root=root->parent;
					break;
			case 3:		
					traversal(root,0);
					break;
			case 4:
					check=1;
					break;
		}
	}
	return 0;
}