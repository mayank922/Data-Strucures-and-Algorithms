#include "stdio.h"
#include "stdlib.h"
int main()
{
  struct node {
    int data;
    struct node *next;
  }*first=NULL;


  int n,a,i,x,index;
  printf("enter size\n" );
  scanf("%d",&n );

  first=(struct node *)malloc(sizeof(struct node));
  struct node *t,*last;
  printf("enter elements\n" );
  scanf("%d", &a);
  first->data=a;
  first->next=NULL;
  last=first;
  for(i=2;i<=n;i++)
  {
    t=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&a );
    t->data=a;
    t->next=NULL;
    last->next=t;
    last=t;

  }

struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("enter the data to insert nad node to insert at" );
scanf("%d %d",&x,&index );
temp->data=x;
if(index==0)
{

temp->next=first;
first=temp;
}
else
for(i=0;i<index-1;i++)
{
  first=first->next;
  temp->next=first->next;
  first->next=temp;
}


while(first!=0)
{
  printf("%d\n",first->data );
  first=first->next;
}


return 0;


}
