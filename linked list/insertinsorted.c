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


  void insertatend(int x)
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



void sortedinsert(struct node *p,int x)

{
  struct node *t,*q=NULL;
  t=(struct node *)malloc(sizeof(struct node));
  t->data=x;
  t->next=NULL;
  if(head==NULL)
  {
    head=t;
  }

else
{
 while(p!=NULL && p->data<x)
 {
 q=p;
 p=p->next;
 }
 if(p==head)
 {
 t->next=head;
 head=t;
 }
 else
 {
 t->next=q->next;
 q->next=t;
 }
 }

}



int main()
{


  // insertatend(5);
  // insertatend(6);
  // insertatend(7);
  // insertatend(9);
  // insertatend(10);
sortedinsert(head,8);
sortedinsert(head,5);
sortedinsert(head,6);


  display(head);







}
