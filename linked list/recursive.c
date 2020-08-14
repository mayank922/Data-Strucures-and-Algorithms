#include "stdio.h"
#include "stdlib.h"
struct node
{
  int data;
  struct node *next; //pointer to next node
}*first=NULL;
void create(int a[],int n)
{
  int i;
  struct node *t,*last;
  first=(struct node *)malloc(sizeof(struct node));
  first->data=a[0];
  first->next=NULL;
  last=first;
  for ( i = 1; i < n; i++) {
    t=(struct node *)malloc(sizeof(struct node));
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
void display(struct node *p)
{

  if(p!=NULL)
  {

    display(p->next);
    printf("%d\n",p->data );
  }
}
int main()
{

  int a[]={3,8,7,6,4,5};
   create(a,6);
  display(first);
}
