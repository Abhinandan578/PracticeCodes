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
// void ReadBTree2(Node** temp,int number,int height)
// {
// 	*temp=(Node *)malloc(sizeof(Node));
// 	int n;
// 	if(number==0)
// 	{
// 		printf("Enter the number of keys the Root have\n");
// 	}
// 	else if(number<0)
// 	{
// 		printf("Enter the number of keys in the node on the right of %d\n",(-1*number));
// 	}
// 	else
// 	{
// 		printf("Enter the number of keys in the node on the left of %d\n",number);
// 	}
// 	scanf("%d",&n);
// 	if(n>(2*t)-1||(n<t-1&&number!=0))
// 	{
// 		printf("Not Possible\n");
// 		ReadBTree2(temp,number,height);
// 	}
// 	(*temp)->N=n;
// 	// (*temp)->keys=(int *)malloc(sizeof(int)*(n+1));
// 	printf("Enter the values of keys in this node\n");
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d",&((*temp)->keys[i]));
// 	}
// 	if(height==1)
// 	{
// 		(*temp)->isLeaf=true;
// 	}
// 	else
// 	{
// 		(*temp)->isLeaf=false;
// 		// (*temp)->child=(Node **)malloc(sizeof(Node *)*(n+2));
// 		for(int i=1;i<=n+1;i++)
// 		{
// 			if(i<n+1)
// 			{
// 				(*temp)->child[i]=ReadBTree((*temp)->child[i],(*temp)->keys[i],height-1);
// 			}
// 			else
// 			{
// 				(*temp)->child[i]=ReadBTree((*temp)->child[i],(-1*(*temp)->keys[i-1]),height-1);	
// 			}
// 			(*temp)->child[i]->parent=(*temp);
// 		}
// 	}
// }
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
			if(i< temp->N + 1)
			{
				// printf("Number is %d\n",temp->keys[i]);
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				// printf("Number is %d\n",(-1*temp->keys[i-1]));
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
				// printf("Number is %d\n",temp->keys[i]);
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				// printf("Number is %d\n",(-1*temp->keys[i-1]));
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
				// printf("Number is %d\n",temp->keys[i]);
				traversal(temp->child[i],temp->keys[i]);
			}
			else
			{
				// printf("Number is %d\n",(-1*temp->keys[i-1]));
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
Node* splitChild(Node* temp,int i,bool* check,int value)
{
	if(temp->N==((2*t)-1))
	{
		printf("Panga\n");
	}
	else
	{
		*check=false;
		temp=sortedInsert(temp,temp->child[i]->keys[t]);
		if(temp->isLeaf==false)
		{
			temp->child[i]->N=t-1;
			temp->child[i+1]->N=t-1;
			int j;
			for(j=t+1;j<=2*t;j++)
			{
				if(j<2*t)
				{
					temp->child[i+1]->keys[j-t]=temp->child[i]->keys[j];
				}
				// if(temp->isLeaf==false)
				// {	
				// 	temp->child[i+1]->child[j-t]=temp->child[i]->child[j];
				// }
			}
		}
		if(value<temp->child[i]->keys[t])
		{
			temp->child[i]=sortedInsert(temp->child[i],value);
		}
		else
		{
			temp->child[i+1]=sortedInsert(temp->child[i+1],value);	
		}
	}
	return temp;
}
Node* InsertUtil(Node* temp,int value,bool* check)
{
	if(temp->N==((2*t)-1))
	{
		(*check)=true;
	}
	else
	{
		temp=sortedInsert(temp,value);
	}
	return temp;	
}
Node* Insert(Node* temp,int value,bool* check,int height)
{
	int i;
	if(height==1)
	{
		temp=InsertUtil(temp,value,check);
	}
	else
	{
		for(i=1;i<=temp->N;i++)
		{
			if(i==1)
			{
				if(temp->keys[i]>value)
				{
					temp->child[i]=Insert(temp->child[i],value,check,height-1);
					break;
				}
				
			}
			else if(i==temp->N)
			{
				if(temp->keys[i]>value&&temp->keys[i-1]<value)
				{
					temp->child[i]=Insert(temp->child[i],value,check,height-1);
					break;
				}
				else if(temp->keys[i]<value)
				{
					temp->child[i+1]=Insert(temp->child[i+1],value,check,height-1);
					break;
				}	
			}
			else
			{
				if(temp->keys[i]>value&&temp->keys[i-1]<value)
				{
					temp->child[i]=Insert(temp->child[i],value,check,height-1);
					break;
				}
			}
		}	
		if(*check==true)
		{
			temp=splitChild(temp,i,check,value);
		}
	}
	return temp;
}
int main()
{
	Node* root;
	int h,value;
	printf("Enter the height of B-Tree\n");
	scanf("%d",&h);
	bool check=false;
	root=ReadBTree(root,0,h);
	// ReadBTree2(&root,0,h);
	traversal(root,0);
	printf("Enter the value to be Inserted in the B-Tree\n");
	scanf("%d",&value);
	root=Insert(root,value,&check,h);
	traversal(root,0);
	return 0;
}