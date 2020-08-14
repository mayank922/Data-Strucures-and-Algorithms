#include "stdio.h"
int main()
{
  int a[50][50];
  int i,j;

  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
    if(j<=i)
    scanf("%ds\n",&a[i][j]);
    }
  }
for(i=0;i<5;i++)
{
  for(j=0;j<5;j++)
  {
    if(j<=i)
    printf("%d", a[i][j]);
    else
    printf("0");

  }
  printf("\n" );
}
}
