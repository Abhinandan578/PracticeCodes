#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct FibNode
{
	FibNode* next=NULL;
	FibNode* prev=NULL;
	FibNode* child=NULL;
	FibNode* parent=NULL;
	int value;
	int degree;
	bool mark;
}FibNode;
typedef struct FibHeap
{
	int N;
	FibNode* Min;
}FibHeap;
FibHeap* CreateFibHeap()
{
	FibHeap* H;
	H=(FibHeap*)malloc(sizeof(FibHeap));
	H->N=0;
	H->Min=NULL;
	return H;
}
FibNode* newNode(int x)
{
	FibNode* temp=(FibNode*)malloc(sizeof(FibNode));
	temp->prev=temp;
	temp->next=temp;
	temp->child=NULL;
	temp->parent=NULL;
	temp->value=x;
	temp->degree=0;
	return temp;
}
FibHeap* Insert(FibHeap* H,int x)
{
	if(H->Min==NULL)
	{
		FibNode* temp=newNode(x);
		H->Min=temp;
	}
	else
	{
		FibNode* node1=H->Min;
		FibNode* node2=newNode(x);
		node2->prev=node1;
		node2->next=node1->next;
		node1->next->prev=node2;
		node1->next=node2;
		if(H->Min->value>node2->value)
		{
			H->Min=node2;
		}		
	}
	H->N++;
	return H;	
}
FibHeap* InsertNode(FibHeap* H,FibNode* x)
{
	if(H->Min==NULL)
	{
		FibNode* temp=x;
		H->Min=temp;
		temp->next=temp;
		temp->prev=temp;
	}
	else
	{
		FibNode* node1=H->Min;
		FibNode* node2=x;
		node2->prev=node1;
		node2->next=node1->next;
		node1->next->prev=node2;
		node1->next=node2;
		if(H->Min->value>node2->value)
		{
			H->Min=node2;
		}		
	}
	return H;	
}
FibHeap* Union(FibHeap* H1,FibHeap* H2)
{
	FibHeap* H=CreateFibHeap();
	if(H1->Min==NULL||H2->Min==NULL)
	{
		if(H1->Min==NULL)
			return H2;
		else
			return H1;
	}
	if(H1->Min->value>H2->Min->value)
	{
		FibNode* temp=H1->Min;
		H1->Min=H2->Min;
		H2->Min=temp;	
	}
	H->Min=H1->Min;
	H1->Min->next->prev=H2->Min->prev;
	H2->Min->prev->next=H1->Min->next;
	H1->Min->next=H2->Min;
	H2->Min->prev=H1->Min;
	return H;
}
void PrintFibHeap(FibHeap* H)
{
	if(H==NULL)
	{
		printf("Heap is Empty\n");
		return;
	}
	FibNode *temp=H->Min;
	printf("Forward traversal is\n");
	do
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
	while(temp!=H->Min);
	printf("\n");
	printf("Backward traversal is\n");
	do
	{
		printf("%d ",temp->value);
		temp=temp->prev;
	}
	while(temp!=H->Min);
	printf("\n");
}
void FibHeapLink(FibHeap* H,FibNode* y,FibNode* x)
{
	FibNode* temp;
	y->prev->next=y->next;
	y->next->prev=y->prev;
	if(x->child==NULL)
	{
		x->child=y;
		y->next=y;
		y->prev=y;
	}
	else
	{
		x->child->next->prev=y;
		y->next=x->child->next;
		y->prev=x->child;
		x->child->next=y;
		if(x->child->value>y->value)
		{
			temp=y;
			y=x->child;
			x->child=temp;
		}
	}
	y->mark=false;
	y->parent=x;
}
void Consolidate(FibHeap* H)
{
	FibNode* arr[1000]={NULL};
	FibNode* root=H->Min;
	FibNode* pres=root,*x,*y,*temp,*nextPres;
	int d;
	if(pres!=NULL)
	{
		do
		{
			nextPres=pres->next;
			x=pres;
			d=x->degree;
			while(arr[d]!=NULL)
			{
				y=arr[d];
				if(x->value>y->value)
				{
					temp=x;
					x=y;
					y=temp;
				}
				FibHeapLink(H,y,x);
				arr[d]=NULL;
				d++;
			}
			arr[d]=x;
			pres=nextPres;
		}
		while(pres!=H->Min);
		H->Min=NULL;
		for (int i = 0; i < 100; ++i)
		{
			if(arr[i]!=NULL)
				InsertNode(H,arr[i]);
		}

	}

}
int ExtractMin(FibHeap* H)
{
	if(H==NULL)
	{
		printf("Empty Heap\n");
		return -1;
	}
	int ret=H->Min->value;
	FibNode* root=H->Min;
	FibNode* child=H->Min->child;
	FibNode* temp=child;
	if(child!=NULL)
	{	
		do
		{
			temp->parent=NULL;
			temp=temp->next;
		}while(temp!=child);
		root->next->prev=child->prev;
		child->prev->next=root->next;
		root->next=child;
		child->prev=root;
	}
	else
	{
		if(root==root->next)
		{
			H->Min=NULL;
			return ret;
		}
	}
	root->next->prev=root->prev;
	root->prev->next=root->next;
	H->Min=root->prev;
	free(root);
	H->N--;
	Consolidate(H);
	return ret;


}
int main()
{
	int check=0;
	FibHeap* H=NULL;
	FibHeap *H1=NULL,*H2=NULL;
	while(check==0)
	{
		int n;
		int value,ans;
		printf("Enter 1 to create a new FibHeap\nEnter 2 to insert a node in FibHeap\nEnter 3 to Print the FibHeap\nEnter 4 to make Union of two heaps\nEnter 5 to Extract minimum element out of the list\nEnter 6 to exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:			
					H=CreateFibHeap();
			case 2:
					printf("Enter the value to be Inserted in the FibHeap\n");
					scanf("%d",&value);
					Insert(H,value);
					break;
			case 3:		
					PrintFibHeap(H);
					break;
			case 4:
					H1=CreateFibHeap();
					int i,n,temp;
					printf("Enter the number of Nodes in 1st Heap\n");
					scanf("%d",&n);
					printf("Enter the values\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&temp);
						H1 = Insert(H1,temp);
					}
					H2=CreateFibHeap();
					printf("Enter the number of Nodes in 2nd Heap\n");
					scanf("%d",&n);
					printf("Enter the values\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&temp);
						H2 = Insert(H2,temp);
					}
					H=Union(H1,H2);
					break;
			case 5:
					ans=ExtractMin(H);
					printf("The minimum element is %d\n",ans);
					break;
			case 6:
					check=1;
					break;
		}
	}
	return 0;
}
