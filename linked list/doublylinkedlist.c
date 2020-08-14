#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *getnode(int data)
{
  struct node *new=(struct node *)malloc(sizeof(struct node));
  new->data=data;
  new->next=new->prev=NULL;
  return new;
}

struct node *head=NULL;
void insertatend(int data)
{
  struct node *new,*temp=head;
  new=getnode(data);

  if(head==NULL)
  head=new;

  else
  {
  while(temp->next!=NULL)
  temp=temp->next;

  temp->next=new;
  new->prev=temp;
  }
}


void iterativedisplay()
{
  struct node *temp=head;
  while(temp!=NULL)
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
}

void recursivedisplay(struct node *temp)
{
  if(temp==NULL)
  return;

  else
  {
    printf("%d\t",temp->data);
    recursivedisplay(temp->next);
  }
}

void iterativecount()
{
  int count=0;
  struct node *temp=head;
  while(temp!=NULL)
  {
    count++;
    temp=temp->next;
  }
  printf("%d\n",count);
}


int recursivecount(struct node *temp)
{
  if(temp==NULL)
  return 0;

  else
  {
    return(1+recursivecount(temp->next));
  }
}

void  deletenodeatn(int n)
{
  struct node *temp=head;
  int i=1;

if(n==1)
{
  head=head->next;
  head->prev=NULL;
  free(temp);
}

else
{
  while(i<n)
  {
    temp=temp->next;
    i++;
  }
    temp->prev->next=temp->next; //NICE
    if(temp->next) //Should be done only if temp->next is not NULL
    temp->next->prev=temp->prev;
    free(temp);
  }
}

void recursivereversedoublylinkedlist(struct node *p)
{
  struct node *prev,*temp,*curr;
  if(p==NULL)
  return;

  else
  {
    curr=p;
    recursivereversedoublylinkedlist(p->next);
    if(p->next==NULL)
    head=p;
    prev=curr->prev;
    curr->prev=curr->next;
    curr->next=prev;
  }
}

void iterativereversedoublylinkedlist(struct node *p)
{
  struct node *temp;
while(p!=NULL)
{
  temp=p->next;
  p->next=p->prev;
  p->prev=temp;

  p=p->prev;

  if(p!=NULL && p->next==NULL) //Before checking p's next we should check if p is NULL or not
  head=p;
}
}


int main()
{
  int ch,value,p,n;
  printf("1-Insert at end\n2-Iteratvedisplay\n3-Recursive Display\n4-Iterative count\n5-Recursive count\n6-Delete node at n(starting from 1)\n7-Reverse doubly linkedlist\n");
  while(1)
{
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:printf("Enter value to be entered:");
            scanf("%d",&value);
            insertatend(value);
            break;

    case 2:iterativedisplay();
    printf("\n");
          break;

    case 3:recursivedisplay(head);
      printf("\n");
        break;

     case 4:iterativecount();
        break;

    case 5:value=recursivecount(head);
        printf("\nThe no. of elements in Linked list is %d\n",value);
         break;

     case 6: printf("Enter the position for deletion of the particular node:");
            scanf("%d",&n);
            deletenodeatn(n);
            break;

      case 7:recursivereversedoublylinkedlist(head);
            break;

      case 8: iterativereversedoublylinkedlist(head);
            break;

 }
}
return 0;
}
