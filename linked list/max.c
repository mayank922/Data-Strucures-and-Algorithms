#include "stdio.h"
#include "stdlib.h"
int main()
{
     struct node
    {
       int data;
       struct node *next; //pointer to next node
    }*first=NULL;

int i,n,max=0;
int a[100];
scanf("%d",&n );
printf("enter the data\n" );
for ( i = 0; i < n; i++)
{
    scanf("%d",&a[i] );
}
  struct node *t,*last;
  first=(struct node *)malloc(sizeof(struct node));
  first->data=a[0];
  first->next=NULL;
  last=first;
  for ( i = 1; i < n; i++)
   {
    t=(struct node *)malloc(sizeof(struct node));
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }

   // while(first!=0)
   // {
   //   printf("%d\n",first->data );
   //   first=first->next;
   // }
   while(first!=NULL)
   {
   if(first->data>max)
   {
     max=first->data;

   }
   first=first->next;
 }
   printf("%d",max );



}
