#include "stdio.h"


void bubble(int a[],int n)
{
  int i,j,flag,temp;
  for(i=0;i<n-1;i++)
  {
    flag=0;//adoptive
    for(j=0;j<n-1;j++)
    {

      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        flag=1;
        }
    }
    if(flag==0)
    {

      break;
    }
  }
}

int main()
{
  int a[1000];
  int n,i;
  printf("enter size\n" );
  scanf("%d\n", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d ", &a[i]);
  }
  bubble(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ", a[i]);
  }


}
