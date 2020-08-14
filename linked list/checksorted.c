#include "stdio.h"
#include "stdlib.h"
struct node
{
  int data;
  struct node *next;
}*head=NULL;

struct node *create(int x)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=x;
  new->next=NULL;
  return new;
}
void atend(int x)
{
  struct node *new=create(x);
  struct node *temp=head;
  if(head==NULL)

    head=new;

  else
   {
  while(temp->next!=NULL)

    temp=temp->next;
    temp->next=new;
  }

}
void display(struct node *p)
{
  while(p!=0)
  {
    printf("%d\n",p->data );
    p=p->next;
  }
}
int sort(struct node *head)
{
  int x=0;
  while(head)
  {
    if(head->data<x)
  
     return 0;
    x=head->data;
    head=head->next;

  }

  return 1;



}


int main()
{

  atend(5);
  atend(6);
  atend(7);
  atend(8);
  atend(9);
  sort(head);
  display(head);

}
