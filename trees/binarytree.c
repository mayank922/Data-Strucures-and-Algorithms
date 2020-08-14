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
struct node *insert(struct node *root,int data)
{
  if(root==NULL)
  {
    return(create(data));
  }
  else if(data<root->data)
  {
    root->left=insert(root->left,data);
  }
  else if(data>root->data)
  {
    root->right=insert(root->right,data);
  }
  return root;
}



void preorder(struct node *t)
{
  if(t!=NULL)
  {
  printf("%d\t", t->data );
  preorder(t->left);
  preorder(t->right);
  }
}
void inorder(struct node *t)
{
  if(t!=NULL)
  {

  inorder(t->left);
  printf("%d\t", t->data );
  inorder(t->right);
  }
}
void postorder(struct node *t)
{
  if(t!=NULL)
  {

  postorder(t->left);
  postorder(t->right);
  printf("%d\t", t->data );
  }
}

int count(struct node *p)
{
int x,y;
if(p!=NULL)
{
  x=count(p->left);
  y=count(p->right);
  return x+y+1;

}
else
return 0;
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


int main()
{
  root=insert(root,10);
  insert(root,6);
  insert(root,13);
  insert(root,5);
  insert(root,7);
  insert(root,11);
  insert(root,14);
  insert(root,15);


  preorder(root);
  printf("\n" );
  inorder(root);
  printf("\n" );
  postorder(root);
  printf("\n" );
  printf("nodes are %d\n",count(root) );
  printf("hieght is %d\n",hieght(root) );


}
