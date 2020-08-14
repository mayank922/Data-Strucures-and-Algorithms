#include "stdio.h"
#include "stdlib.h"

struct node
{
  struct node *left;
  int data;
  struct node *right;
}*root=NULL;

struct node *create(int x)
{
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  p->data=x;
  p->left=p->right=NULL;
  return p;
}
struct node *rinsert(struct node *root,int data) //every time left=right will be 0 before entering
{
  if(root==NULL)
  {
    return(create(data));
  }
  else if(data<root->data)
  {
    root->left=rinsert(root->left,data);
  }
  else if(data>root->data)
  {
    root->right=rinsert(root->right,data);
  }
  return root;
}
struct node  *rsearch(struct node *t,int key)
{

  if(t==NULL)
  {
  return NULL;
  }
  else if(key==t->data)
  {
    return t;
  }
  else if(key<t->data)
  {
    return rsearch(t->left,key);
  }
  else
  {
  return rsearch(t->right,key);
  }
}

struct node  *search(struct node *t,int key)
{

  while(t!=NULL)
  {
   if(key==t->data)
  {
    return t;
  }
  else if(key<t->data)
  {
    t=t->left;
  }
  else
  t=t->right;
  }
  return NULL;
}
void inorder(struct node *t)//wll always represent sorted order of tree
{
  if(t!=NULL)
  {

  inorder(t->left);
  printf("%d\t", t->data );
  inorder(t->right);
  }
}

int hieght(struct node *p)
{
   int x=0,y=0;
  if(p==NULL)
 {
  return 0;
 }
  else
  {
  x=hieght(p->left);
  y=hieght(p->right);
  if(x>y)
  {return x+1;}
  else
   {  return y+1;}
  }
}

struct node *inpre(struct node *t)//left tree rightmost node
{
  while(t && t->right!= NULL)
    {  t=t->right;
    }
      return t;
}
struct node *insuc(struct node *t)//right tree leftmost node
{
  while(t && t->left!= NULL)
    {  t=t->left;
    }
      return t;
}


struct node  *delete(struct node *t,int key)//search and delelte
{
struct node *q;
if(key<t->data)
{
  t->left=delete(t->left,key);

}
else if(key>t->data)
{
  t->right=delete(t->right,key);
}
else//key found replace with pre or suc
{
  if(hieght(t->left)>hieght(t->right))
  {
  q=inpre(t->left);
  t->data=q->data;
  t->left=delete(t->left,q->data);//used recurssion if the deleted node may have child
  }
  else
  {
    q=insuc(t->right);
  t->data=q->data;
  t->right=delete(t->right,q->data);
  }
}
return t;
}
int main()
{
  struct node *temp1,*temp2;
  root=rinsert(root,10);
  rinsert(root,6);
  rinsert(root,13);
  rinsert(root,5);
  rinsert(root,7);
  rinsert(root,11);
  rinsert(root,14);
  rinsert(root,15);
  temp1=rsearch(root,11);
  temp2=search(root,14);

printf("found %d\n",temp1->data);
printf("found %d\n",temp2->data);

   delete(root,15);

inorder(root);
}
