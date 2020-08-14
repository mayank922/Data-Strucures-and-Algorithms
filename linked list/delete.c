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

void deletenode(struct node *head,int pos)
{
  struct node *q=NULL;
  int i;
  if(pos==1)
  {
    q=head;
    head=head->next;
    free(q);
  }
  else
   {
     for(i=0;i<pos;i++ )
     {
       q=head;
       head=head->next;

     }
     q->next=head->next;
     free(head);

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
int main()
{


  atend(5);
  atend(4);
  atend(7);
  atend(9);
  atend(10);
  deletenode(head,4);
  display(head);







}
