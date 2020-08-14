#include "stdio.h"
void insertion(int a[], int n)
{
  int i,j,x;
  for(i=0;i<n;i++)
  {
    j=i-1;
    x=a[i];
    while(j>-1 && a[j]>x)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=x;
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
  insertion(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ", a[i]);
  }


}
