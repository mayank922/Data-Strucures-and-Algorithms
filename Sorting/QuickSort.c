#include "stdio.h"
#include "limits.h"

int partition(int a[],int l,int h)
{
  int pivot=a[l];
  int i=l,temp1,temp2,j=h;
do{
  do{i++;}while(a[i]<=pivot);
   do{j--;}while(a[j]>pivot);
    if(i<j)
    {
        temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;
      }
  }while(i<j);
   temp2=a[l];
   a[l]=a[j];
   a[j]=temp2;


  return j;
}

void quicksort(int a[],int l,int h )
{
  int j;
  if(l<h)
  {
    j=partition(a,l,h);
    quicksort(a,l,j);
    quicksort(a,j+1,h);
  }
}
int main()
{
  int a[1000];
  int n,i;
  printf("enter size\n" );
  scanf("%d", &n);
  a[n]=655534;
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  int l=i;
  int h=n;
  quicksort(a,l,h-1);
  for(i=0;i<n;i++)
  {
    printf("%d ", a[i]);
  }


}
