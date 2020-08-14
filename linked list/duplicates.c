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
void dupli(struct node *head)
{
  struct node *q=head->next;
  while(q!=NULL)
  {
    if(head->data!=q->data)
    {
      head=q;
      q=q->next;
    }
    else
    {
      head->next=q->next;
    free(q);
    q=head->next;
    }
  }

}
int main()
{

  atend(6);
  atend(7);
  atend(7);
  atend(8);
  atend(1);
  dupli(head);

  display(head);
}
