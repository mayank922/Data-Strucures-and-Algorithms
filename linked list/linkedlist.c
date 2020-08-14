#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};


struct node *head=NULL;

struct node *getnode(int data)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=data;
  new->next=NULL;
  return new;
}


void insertatend(int data)
{
  struct node *new=getnode(data);
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

void insertatn(int value,int n)
{
  struct node *temp2=head,*temp1=head,*temp=getnode(value);
  int i=0;
  if(n==0) //INSERT IN BEGINNING I.E IT BECOMES THE FIRST NODE
  {
    temp->next=head;
    head=temp;
  }

  else //n=1 means it should the node should be inserted after first node and before second node
  {
  for(i=1;i<n;i++) //E.g-> for second element there should be one traversal
    {
    temp1=temp1->next;  // points to element after which node is inserted
    }
    temp2=temp1->next;  // points to element which should be present after node


  temp1->next=temp;
  temp->next=temp2;
   }
}

void insertinsortedlist(int value)
{
  struct node *prev,*temp=head;
  struct node *new=getnode(value);
  while(temp!=NULL && temp->data < value)
  {
    prev=temp;
    temp=temp->next;
  }
  if(value<head->data)
  {
  new->next=temp;
  head=new;
  }
  else
  {
    prev->next=new;
    new->next=temp;
  }
}

void recursivedisplay(struct node *head)
{
  if(head==NULL)
  return;

  else
  {
    printf("%d\t",head->data);
    recursivedisplay(head->next);
  }
}


void iteratvedisplay(struct node *head)
{
  while(head!=NULL)
  {
    printf("%d\t",head->data);
    head=head->next;
  }
}

void recursivereversedisplay(struct node *temp)
{
  if(temp==NULL)
  return;
  else
  {
    recursivereversedisplay(temp->next);
    printf("%d\t",temp->data);
  }
}

void iterativecount(struct node *head)
{
  int count=0;
  while(head!=NULL)
  {
    count++;
    head=head->next;
  }
  printf("\nThe no. of elements in Linked list is %d\n",count);
}

int recursivecount(struct node *head)
{
  if(head==NULL)
  return 0;

  else
  {
    //return recursivecount(head->next)+1;
    return 1+recursivecount(head->next);
  }
}

void iterativesumofall(struct node *head)
{
  int sum=0;
  while(head!=NULL)
{
  sum+=head->data;
head=head->next;
}
  printf("\nThe sum of all elements is %d\n",sum);
}



int recursivesumofall(struct node *head)
{
  if(head==NULL)
  return 0;

  else
  return recursivesumofall(head->next)+head->data;
}


void iterativemax(struct node *temp)
{
  int max=head->data; //Global head node declared i.e first element

  while(temp!=NULL)
  {
    if(temp->data > max)
    max=temp->data;

    temp=temp->next;
  }

  printf("The maximum value in a linked list is %d\n",max);
}


/*int recursivemax(struct node *temp,int max)  // MY CODE
{
  if(temp==NULL)
  return max;

  else if(temp->data > max)
  return recursivemax(temp->next,temp->data);

  else
  return recursivemax(temp->next,max);

}*/

  int recursivemax(struct node *temp)
  {
    int x=0;

    if(temp==NULL)
    return 0;

    x=recursivemax(temp->next);

    return x>temp->data?x:temp->data;

}


void iterativesearch(struct node *head,int key) //If no duplicates are present
{
  while(head!=NULL)
  {
    if(key==head->data)
    {
    printf("\nKey found\n");
    break;
  }
    head=head->next;
  }
  if(head==NULL)
  printf("\nKey not found\n");
}

int recursivesearch(struct node *head,int key)
{
  if(head==NULL)
  return -1;
  else if(head->data==key)
  {
    return 1;
  }
  else
  return recursivesearch(head->next,key);
}

void deletenode(int position)
{
  struct node *prev,*temp=head;
  int i=1; //For traversal

  if(position==1)
  {
    head=head->next;  //Deletinf the first node therefore we have to move the head node to the next pointer
    free(temp); //Deleting the head(first) node
  }

  else
  {
    while( i>0 && i!=position && temp!=NULL) //check for positive index
    {
      prev=temp; //Pointing to one node prevoius to temp(temp being the required node to be deleted)
      temp=temp->next; //Traversal
      i++;
    }
    if(temp!=NULL && i>0)
    {
    prev->next=temp->next;
    free(temp);
    printf("Deletion successfull\n");
    }
    else
    printf("Deletion Unsuccessfull\n");
  }
}

/*void checklistissorted()  //MY CODE
{
  struct node *curr=head;
  struct node *prev=head;

  while(curr !=NULL)
  {
    prev=curr;
    curr=curr->next;

    if(prev->data < curr->data && curr->next==NULL)
    {
      printf("List is sorted in Ascending order");
      break;
    }

      else if(prev->data > curr->data)
      {
      printf("Not sorted list");
      break;
      }

    /*else if(prev->data > curr->data && curr->next==NULL)
    printf("List is sorted in Descending order");/*



  }
}*/


int checklistissorted()
{
  struct node *curr=head->next;
  int x=head->data;

  while(curr!=NULL)
  {
  if(x > curr->data)  //x=next element in list(with respect to curr) curr is the current element in list
  return 0;

  x=curr->data;
  curr=curr->next;
  }
  return 1;
}

void iterativereverse() //Reversing the Links
{
  struct node *prev=NULL;
  struct node *curr=NULL;
  struct node *next=head;

  while(next!=NULL)
  {
    prev=curr;
    curr=next;
    next=next->next;

    curr->next=prev;
  }
  if(next==NULL)
  head=curr;
}



void recursiverevesre(struct node *curr,struct node *prev)
{
  if(curr!=NULL) //cuur->next will work if curr->next=prev in else statement(make recursive tree to understand)
  {
  recursiverevesre(curr->next,curr);
  curr->next=prev;
  }
  else
  {
    head=prev;
    //head=curr;
   //curr->next=prev; //for curr->next to work in if statement
  }
}


int main()
{
  int ch,value,p,n;
  printf("1-Insert at end\n2-Recursive display\n3-Iteratvedisplay\n4-Recursive reverse display\n5-Iterativecount\n6-Recursivecount\n7-Iterativesumofall\n8-Recursivesumofall\n9-Iterativemax\n10-Recursivemax\n11-Iterative search\n12-Recursive search\n13-Insert at any position\n14-Insert in sorted list\n15-Delete node at any position(starting from 1)\n16-To check if list is sorted(Ascending order)\n17-Iterative Reverse\n18-Recursive Reverse\n");
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

  case 2:recursivedisplay(head);
    printf("\n");
          break;

  case 3:iteratvedisplay(head);
    printf("\n");
        break;

  case 4:recursivereversedisplay(head);
    printf("\n");
      break;

  case 5:iterativecount(head);
    break;

    case 6:value=recursivecount(head);
    printf("\nThe no. of elements in Linked list is %d\n",value);
       break;

    case 7:iterativesumofall(head);
      break;


    case 8:value=recursivesumofall(head);
    printf("\nThe sum of all elements is %d\n",value);
    break;

    case 9:iterativemax(head->next);
      break;

    case 10://value=recursivemax(head->next,head->data); //MY CODE
      value=recursivemax(head);
        printf("The maximum value in a linked list is %d\n",value);
          break;

    case 11:printf("Enter the key to be searched:");
            scanf("%d",&value);
            iterativesearch(head,value);
            break;


    case 12:printf("Enter the key to be searched:");
            scanf("%d",&value);
            p=recursivesearch(head,value);
            if(p==1)
            printf("\nKey found\n" );
            else
            printf("\nKey not found\n");
            break;

    case 13:  printf("Enter value to be entered and index position:");
            scanf("%d%d",&value,&n);
            insertatn(value,n);
            break;


  case 14:printf("Enter value to be entered:");
          scanf("%d",&value);
          insertinsortedlist(value);
          break;

 case 15: printf("Enter the position for deletion of the particular node:");
          scanf("%d",&n);
          deletenode(n);
          break;

 case 16:n=checklistissorted();
          if(n==0)
          printf("List is not sorted in Ascending order");
          else
            printf("List is sorted in Ascending order");
          break;

 case 17:iterativereverse();
        break;

  case 18:recursiverevesre(head,NULL);
         break;

 case 19:exit(0);
        break;
  }
}

return 0;
}
