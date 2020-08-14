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
int loop(struct node *head)
{
  struct node *p,*q;
  q=p=head;
  do
  {
    p=p->next;
    q=q->next;
    if(q!=NULL)  //move q two node ahead
    {
      q=q->next;
    }
  }while(p && q && p!=q);

   if(p==q)
   return 1;
   else
   return 0;


}
int main()
{
struct node *t1,*t2;
  atend(6);
  atend(7);
  atend(8);
  atend(9);
  atend(10);
  t1=head->next->next;
  t2=head->next->next->next->next;
  t2->next=t1;
  printf("%d\n",loop(head));
  // display(head);
}
