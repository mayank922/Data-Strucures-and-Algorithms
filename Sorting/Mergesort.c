#include "stdio.h"
void merge(int a[],int l,int mid,int h)
{
  int i=l,j,k=l;
  j=mid+1;
  i=l;
  int b[100];
  while(i<=mid && j<=h)
  {
    if(a[i]<a[j])
    {
      b[k++]=a[i++];
    }
    else
    {
      b[k++]=a[j++];
    }
  }
for(;i<=mid;i++)//remianing elements
{
  b[k++]=a[i];
}
for(;j<=h;j++)
{
  b[k++]=a[i];
}

  for(i=l;i<=h;i++)
  {
    a[i]=b[i];
  }
}

void imergesort(int a[],int n)
{
  int i,p,l,h,mid;
  for(p=2;p<=n;p=p*2)
  {
    for(i=0;i+p-1<n;i=i+p)
    {
      l=i;
      h=i+p-1;
      mid=(l+h)/2;
      merge(a,l,mid,h);
    }
  }
  if(p/2<n)
  {
    merge(a,0,p/2-1,n-1);
  }
}

void rmergesort(int a[],int l,int h)
{
  int mid;
  if(l<h)
  {

    mid=(l+h)/2;
    rmergesort(a,l,mid) ;
    rmergesort(a,mid+1,h);
    merge(a,l,mid,h);

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
  mergesort(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ", a[i]);
  }


}
