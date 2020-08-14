#include "stdio.h"

void selection(int a[],int n)
{
  int i,j,k,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=k=i;j<n;j++)
    {
      if(a[j]<a[k])
      {
         k=j;
      }
      temp=a[i];
      a[i]=a[k];
      a[k]=temp;
    }
  }
}


int main()
{
  int a[1000];
  int n,i;
  printf("enter size\n" );
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  selection(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ", a[i]);
  }


}
