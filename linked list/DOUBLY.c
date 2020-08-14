#include "stdio.h"
#include "stdlib.h"

struct node
{
  struct node *prev;
  int data;
  struct node *next;
}*head=NULL;

struct node *create(int x)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->prev=NULL;
  new->data=x;
  new->next=NULL;
  return new;
}
void atend(int x)
{
  struct node *new=create(x);
  struct node *temp=head;
  if(head==NULL)
  {
    head=new;
  }
  else
  {
  while(temp->next!=NULL)
  temp=temp->next;


  temp->next=new;
  new->prev=temp;
}
}
void display(struct node *p)
{
  while(p)
  {
    printf("%d\n",p->data );
    p=p->next;
  }
}
void insert(struct node *head,int pos,int k)
{
  int i;
  struct node *t,*q;
  t=(struct node *)malloc(sizeof(struct node));
  t->prev=NULL;
  t->data=k;
  t->next=NULL;
  if(pos==0)
  {
    t->next=head;
    head=t;
    head->prev=t; //for doubly
  }
  else
  for(i=0;i<pos;i++)
  {
    q=head;
    head=head->next;

  }
  q->next=t;
  t->next=head;
  head->prev=t;
  t->prev=q;
  }
  void delete(int pos)
  {
    struct node *p=head;
    int i;

     if(pos==1)
     {
       head=head->next;
       head->prev=NULL;
       free(p);

     }
     else
     {
       for(i=0;i<pos-1;i++)
       {
         p=p->next;

       }
       p->prev->next=p->next;
       if(p->next!=NULL)
       p->next->prev=p->prev;
       free(p);

     }

}
  void reverse(struct node *head)
  {
    struct node *p;
    while(head)
    {
      p=head->next;
      head->next=head->prev;
      head->next=p;
      head=head->prev;
      if(head!=NULL && head->next==NULL)
        head=head;
  }
  }
int main()
{
  atend(5);
  atend(6);
  atend(7);
  atend(8);
  atend(9);

  // insert(head,1,9);
  // delete(3);
  reverse(head);
  display(head);
}
