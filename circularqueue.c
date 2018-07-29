#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct circular_queue
{
        int d[max];
        int front;
        int rear;
}cqueue;

void create_cqueue(cqueue* );
void enqueue(cqueue* ,int );
void dequeue(cqueue*);
void display(cqueue* );

int main()
{
    int choice,d;
    char ch;
    cqueue cq;
    create_cqueue(&cq);
    do
    {
         printf("\n1.enqueue\t2.dequeue\t3.display\t4.exit : ");
         scanf("%d",&choice);
         switch(choice)
         {
                 case 1 :  printf("\nEnter element : ");  
                           scanf("%d",&d);
                           enqueue(&cq,d);
                           break;
                 case 2 :  dequeue(&cq);
                           break;
                 case 3 :  display(&cq);
                           break;
                 case 4 : exit(1); 
                 default : printf("\nEnter correct choice - ");
         }
         fflush(stdin);
         printf("\ndo you want to continue(y/n) : ");
         ch=getchar();
    }while(ch=='y' || ch=='Y');
    
    return 0;
}

void create_cqueue(cqueue* cq1)
{          
         cq1->rear = -1;
         cq1->front = 0;
}           

void enqueue(cqueue* cq1,int d1)
{
     if( ((cq1->rear == max-1)&&(cq1->front ==0)) || ((cq1->rear != -1)&&(cq1->front == cq1->rear +1)) )   
     {
         printf("\nOverflow");
         return;
     }    
     else 
       if( (cq1->rear == max-1)||(cq1->rear ==-1) )
        cq1->rear =0;
       else 
         cq1->rear++;
        
         cq1->d[cq1->rear]=d1;
}
void dequeue(cqueue* cq1)
{
     if (cq1->rear==-1)
     {
       printf("\nUnderflow"); 
       return;
     } 
      printf("element deleated : %d",cq1->d[cq1->front]);  
       if(cq1->front==cq1->rear)
       {
           cq1->front=-1;
           cq1->rear=-1;
       }
       else
           if (cq1->front==(max-1))
             cq1->front=0;
            else   
             cq1->front++; 
}         

void display(cqueue* cq1)
{
     int i;
     printf("\ncircular Queue : ");
     if(cq1->rear > cq1->front)
      for(i=cq1->front ; i<= cq1->rear ;i++)
       printf("\t%d",cq1->d[i]);   
           
     else
      {
        for(i=cq1->front ; i<= max-1 ; i++)
          printf("\t%d",cq1->d[i]);
        for(i=0 ; i<= cq1->rear ;i++)
          printf("\t%d",cq1->d[i]);
      }
}              
     
     
         
      
            





                                                   
