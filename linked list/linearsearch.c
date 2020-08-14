#include "stdio.h"
#include "stdlib.h"
int main()
{
     struct node
    {
       int data;
       struct node *next; //pointer to next node
    }*first=NULL;

int i,n,max=0,k=0,b;
scanf("%d",&n );
printf("enter the data\n" );

  struct node *t,*last;
  first=(struct node *)malloc(sizeof(struct node));
  scanf("%d\n", &b);
  first->data=b;
  first->next=NULL;
  last=first;
  for ( i = 2; i <=n; i++)
   {
    t=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&b );
    t->data=b;
    t->next=NULL;
    last->next=t;
    last=t;
  }

     // while(first!=0)
     // {
     //   printf("%d\n",first->data );
     //   first=first->next;
     // }
     printf("enter key\n" );
     scanf("%d",&k );
     while(first!=NULL)
     {
       if(k==first->data)
       {
       printf("found at %d\n",first->data);
       break;}
       first=first->next;
       }


return 0;

     }
