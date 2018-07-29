#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
       int t;
       struct node *next;
}n;
// typedef struct node n;       


void push(n**, int );
void pop(n**);
void display(n*);

int main()
{
    int d,c;
    n *top =NULL;
     while(1)
    {
            
            printf("\nPress 1 to push a number into the stack ");
            printf("\nPress 2 to pop a number into the stack ");
            printf("\nPress 3 to display the stack ");
            printf("\nPress 4 to exit ");
            scanf("%d",&c);
            
            switch(c)
            {
                     case 1 :  printf("\nnumber to be pushed into stack = ");
                               scanf("%d",&d);

                               push(&top,d);
                               break;
                     
                     case 2 :  pop(&top);
                               break;
                     case 3 :  printf("\nThe stack is as follows : \n");
                               display(top);
                               break;
                     case 4 :  exit(0);
                     default : printf("\nEnter correct number : ");
            }
    }
    return 0;
}

void push(n** top1, int d)
{
     n* p;
     p = (n*)malloc(sizeof(n));
     p->t = d;
     p->next = (*top1);
     *top1=p;
     
}
    
    
void pop(n** top1)
{
     n* p;
     if(*top1==NULL)
     printf("\nunderflow");
     else
       {
          printf("\nElement poped out : %d", (*top1)->t);
          p=*top1;
          *top1=(*top1)->next;
          free(p);
       }
}


void display(n* top1)
{
    n *p;
    p=top1;
     while( p!=NULL)
     { 
         printf("\t%d",p->t); 
         p= p->next;
     }
}                  
