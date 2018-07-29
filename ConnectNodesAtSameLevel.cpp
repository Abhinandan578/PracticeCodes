#include<iostream>
#include<queue>
#include<malloc.h>
using namespace std;
struct node
{
	int value;
	struct node* left;
	struct node* right;
	struct node* nextRight;
};
struct node* newNode(int data)
{
	// struct node *temp=(struct node*)malloc(sizeof(struct node)); 
	struct node* temp=new node;
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
		cout<<temp->value<<" ";
		temp=temp->nextRight;
	}
	cout<<endl;
	root=(root->left)?root->left:root->right;
	printSpecial(root);
}
void connect(struct node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	int l,count;
	while(q.empty()!=true)
	{
		l=1;
		count=q.size();
		struct node* ptr=NULL,*temp;
		while(l<=count)
		{
			temp=q.front();
			q.pop();
			if(ptr==NULL)
			{
				ptr=temp;
				temp->nextRight=NULL;
			}
			else
			{
				ptr->nextRight=temp;
				ptr=temp;
			}
			if(temp->left)
			{
				q.push(temp->left);
			}
			if(temp->right)
			{
				q.push(temp->right);
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