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
  int main()
  {
    int x,i,n;
    printf("enter no of nodes" );
    scanf("%d\n",&n );
    for(i=0;i<n;i++)
    {
      scanf("%d",&x );
      insertatend(x);
    }


    display(head);


  }
