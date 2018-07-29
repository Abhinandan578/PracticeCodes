#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insertNode(struct node** root,int value)
{
    if((*root)==NULL)
    {
        (*root)=newNode(value);
        return;
    }
    if((*root)->data>value)
    {
        if((*root)->left==NULL)
        {
            (*root)->left=newNode(value);
        }
        else
        {
            insertNode(&((*root)->left),value);
        }
    }
    else if((*root)->data<=value)
    {
        if((*root)->right==NULL)
        {
           (*root)->right=newNode(value);
        }
        else
        {
            insertNode(&((*root)->right),value);
        }
    }
    return;
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int search_value(struct node* root,int key)
{
    if(root==NULL)
        return 0;
    if(root->data>key)
    {
        return search_value(root->left,key);
    }
    else if(root->data<key)
    {
        return search_value(root->right,key);
    }
    else if(root->data==key)
    {
        return 1;
    }
}
struct node* findSuccesor(struct node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return findSuccesor(root->left);
    }
}
struct node* deleteNode(struct node* root,int value)
{
    if(root==NULL)
        return NULL;
    if(root->data==value)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            return NULL;
        }
        else
        {
            if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
            {
                struct  node* temp=findSuccesor(root->right);
                  root->data=temp->data;
                  root->right=deleteNode(root->right,root->data);
                return root;
            }
        }
    }
   else if(root->data<value)
    {
        root->right=deleteNode(root->right,value);
    }
   else
   {
      root->left=deleteNode(root->left,value);
   }
   return root;

}
int main()
{
    int check=0;
    struct node* root=NULL;
    while(check==0)
    {
        printf("Press 1 for creating a new tree \nPress 2 for inserting a node in a tree \nPress 3 to print the inorder traversal of tree \nPress 4 to search a given node in tree \nPress 5 to delete node in a tree\n Press 6 to exit\n");
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                    printf("Enter No of nodes in BST \n");
                    int nodes;
                    scanf("%d",&nodes);
                    int value,i;
                    printf("Enter the values in BST \n");
                    root=NULL;
                    for(i=0;i<nodes;i++)
                    {
                        scanf("%d",&value);
                        insertNode(&root,value);
                    }
                    break;
            case 2:
                    if(root==NULL)
                    {
                        printf("Tree is not constructed\n");
                    }
                    else
                    {
                        printf("Enter the value to be inserted\n");
                        int value;
                        scanf("%d",&value);
                        insertNode(&root,value);
                    }
                    break;
            case 3:
                    if(root==NULL)
                    {
                        printf("Tree is not constructed\n");
                    }
                    else
                    {
                        printf("Inoder Traversal is \n");
                        inorder(root);
                        printf("\n");
                    }
                    break;
            case 4:
                    printf("Enter the key to be searched in a tree\n");
                    int key;
                    scanf("%d",&key);
                    if(search_value(root,key)==1)
                    {
                        printf("The key is present\n");
                    }
                    else
                    {
                        printf("The key is absent\n");
                    }
                    break;
            case 6:
                    check=1;
                    break;
            case 5:
                        printf("Enter the value to be deleted");
                        int valueDel;
                        scanf("%d",&valueDel);
                        if(search_value(root,valueDel)==1)
                        {
                                root=deleteNode(root,valueDel);
                                inorder(root);
                        }
                        else
                        {
                                 printf("The value is absent.Enter the right value.\n");
                        }
                        break;
        }
    }
    return 0;
}