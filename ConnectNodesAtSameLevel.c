#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node* left;
	struct node* right;
	struct node* nextRight;
};
struct node** createQueue(int *front,int *rear)
{
	struct node** queue=(struct node**)malloc(sizeof(struct node*)*500);
	*rear=0;
	*front=1;
	return queue;
}
void enQueue(struct node** queue,int* rear,struct node* node)
{
	queue[(*rear)+1]=node;
	(*rear)++;
}
struct node* deQueue(struct node** queue,int* front)
{
	(*front)++;
	struct node* temp=queue[(*front)-1];
	return temp;
}
int sizeOfQueue(int  front,int rear)
{
	return rear-front+1;
}
struct node* newNode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node)); 
	// struct node* temp=new node;
	temp->left=temp->right=temp->nextRight=NULL;
	temp->value=data;
	return temp;
}
void printSpecial(struct node* root)
{
	if(root==NULL)
		return;
	struct node * temp=root;
	while(temp)
	{
		printf("%d ",temp->value );
		temp=temp->nextRight;
	}
	printf("\n");
	root=(root->left)?root->left:root->right;
	printSpecial(root);
}
void connect(struct node* root)
{
	printf("HEllo\n");
	int front;
	int rear;
	struct node** queue=createQueue(&front,&rear);
	struct node* temp;
	enQueue(queue,&rear,root);
	struct node* ptr;
	// printf("%d \n",ptr->value );
	int l,count;
	while(sizeOfQueue(front,rear)!=0)
	{
		l=1;
		count=sizeOfQueue(front,rear);
		ptr=NULL;
		while(l<=count)
		{
			temp=deQueue(queue,&front);
			if(ptr==NULL)
			{
				ptr=temp;
				ptr->nextRight=NULL;
			}
			else
			{
				ptr->nextRight=temp;
				ptr=temp;
			}
			if(temp->left)
			{
				enQueue(queue,&rear,temp->left);
			}
			if(temp->right)
			{
				enQueue(queue,&rear,temp->right);
			}
			l++;
		}
	}
}
int main()
{
	struct node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	connect(root);
	printSpecial(root);
	return 0;
}