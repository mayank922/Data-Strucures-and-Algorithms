#include "stdio.h"


void insert(int a[],int n)
{

   int i=n;
   int temp;
   temp=a[i];
   while(i>1 && temp>a[i/2])
   {
     a[i]=a[i/2];
     i=i/2;
   }
   a[i]=temp;

}
int delete(int a[],int n)
{
  int i ,j,x,val,temp;
  val=a[1];
  x=a[n];//delete last one
  a[1]=a[n];
  a[n]=val;
  i=1;
  j=i*2;

  while(j<=n-1)//n-1 as we store deleterd element iin last empty space
  {
    if(a[j+1]>a[j] && j<n-1)
    {
      j=j+1;
    }
    if(a[i]<a[j])
    {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      i=j;
      j=2*j;
    }
    else
    {
    break;
    }
  }
  return   val;
}

int main()
{
  int  H[]={0,10,20,30,25,5,40,35};
  int i;
  for(i=2;i<=7;i++)
  {
    insert(H,i);
  }
  for ( i = 1; i <=7; i++)
  {
    printf("%d ", H[i]);
  }
  printf("\n" );
  for(i=7;i>1;i--)
  {
     delete(H,i);
  }
  for ( i = 1; i <=7; i++)
  {
    printf("%d ", H[i]);
  }

return 0;

}
