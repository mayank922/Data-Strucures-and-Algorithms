#include "stdio.h"
int main()
/*{
  int a[10];
  int i,j,x;
  set(&a[5],1,1,3);
  set(&a[5],2,2,5);
  set(&a[5],3,3,6);
  set(&a[5],4,4,8);
  set(&a[5],5,5,9);
  display(5);

}
void set(int a[],int i,int j,int x)
{
  if(i==j)
  {
    a[i-1]=x;
  }
}
int get(int a[],int i,int j)
{
  if(i==j)
  {
    return a[5]a[i-1];
  }
  else return 0;
}
void display(int a[])
{
  for(i=0;i<5;i++)
  {
    for(l=0;j<5;j++)
    {
      if(i==j)
      printf("%d\n",a[5]a[i] );
      else
      printf("0");
    }
  }
}*/
{
  int a[50];
  int i,j,x;

  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
    if(i==j)
    scanf("%ds\n",&a[i]);
    }
  }
for(i=0;i<5;i++)
{
  for(j=0;j<5;j++)
  {
    if(i==j)
    printf("%d", a[i]);
    else
    printf("0");

  }
  printf("\n" );
}
}
//using structures
/*Diagonal Matrix C
#include <stdio.h>
struct Matrix
{
 int A[10];
 int n;
};
void Set(struct Matrix *m,int i,int j,int x)
{
 if(i==j)
 m->A[i-1]=x;

}
int Get(struct Matrix m,int i,int j)
{
 if(i==j)
 return m.A[i-1];
 else
 return 0;
}
void Display(struct Matrix m)
{
 int i,j;
 for(i=0;i<m.n;i++)
 {
 for(j=0;j<m.n;j++)
 {
 if(i==j)
 printf("%d ",m.A[i]);
 else
 printf("0 ");
 }
 printf("\n");
 }
}
int main()
{
 struct Matrix m;
 m.n=4;

 Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,
4,4,12);
 printf("%d \n",Get(m,2,2));
 Display(m);
 return 0;
}*/
