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
  new->next=head;
  return new;
}
void atend(int x)
{
  struct node *new=create(x);
  struct node *temp=head;
  if(head==NULL)
{    head=new;
    new->next=head;
}
  else
   {
while(temp->next!=head)
  temp=temp->next;


  temp->next=new;

  }

}
void display(struct node *p)
{

  do
  {
   printf("%d\n", p->data  );
    p=p->next;
  }while(p!=head);
}
// int Length(struct Node *p)
// {
//  int len=0;
//  do
//  {
//  len++;
//  p=p->next;
//
//  }while(p!=Head);
//  return len;
// }
// void Insert(struct Node *p,int index, int x)
// {
//  struct Node *t;
//  int i;
//  if(index<0 || index > Length(p))
//  return;
//
//  if(index==0)
//  {
//  t=(struct Node *)malloc(sizeof(struct Node));
//  t->data=x;
//  if(Head==NULL)
//  {
//  Head=t;
//  Head->next=Head;
//  }
//  else
//  {
//  while(p->next!=Head)p=p->next;
//  p->next=t;
//  t->next=Head;
//  Head=t;
//  }
//
//  }
//  else
//  {
//  for(i=0;i<index-1;i++)p=p->next;
//  t=(struct Node *)malloc(sizeof(struct Node));
//  t->data=x;
//  t->next=p->next;
//  p->next=t;
//
//  }
// }
// int Delete(struct Node *p,int index)
// {
//  struct Node *q;
//  int i,x;
//
//  if(index <0 || index >Length(Head))
//  return -1;
//  if(index==1)
//  {
//  while(p->next!=Head)p=p->next;
//  x=Head->data;
//  if(Head==p)
//  {
//  free(Head);
//  Head=NULL;
//  }
//  else
//  {
//  p->next=Head->next;
//  free(Head);
//  Head=p->next;
//  }
//  }
//  else
//  {
//  for(i=0;i<index-2;i++)
//  p=p->next;
//  q=p->next;
//  p->next=q->next;
//  x=q->data;
//  free(q);
//  }
//  return x;
// }
int main()
{

  atend(6);
  atend(7);
  atend(8);
  atend(9);
  atend(10);

  display(head);
}
