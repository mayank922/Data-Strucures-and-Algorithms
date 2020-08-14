#include "stdio.h"
int main()
{
  int a[50][50];
  int i,j;
  int row,column;
  printf("enter the column and rows you desire\n" );
  scanf("%d%d",&column,&row );
printf("enter the elements\n" );

  for(i=0;i<column;i++)
  {
    for(j=0;j<row;j++)
    {
    if(i<=j)
    scanf("%ds\n",&a[i][j]);
      a[j][i]=a[i][j];
    }
  }
for(i=0;i<column;i++)
{
  for(j=0;j<row;j++)
  {
  
    printf("%d", a[i][j]);


  }
  printf("\n" );
}
}
