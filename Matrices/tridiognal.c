#include "stdio.h"
int main()
{
  int a[50][50];
  int i,j;
  int row,column;
  printf("enter the columns and rows respt\n" );
  scanf("%d%d",&column,&row );
  printf("enter the elements\n" );
  for(i=0;i<column;i++)
  {
    for(j=0;j<row;j++)
    {
      if(i==j)
      scanf("%d\n",&a[i][j] );
      else if(i-j==1)
      scanf("%d\n",&a[i][j] );
      else if (i-j==-1)
      scanf("%d\n",&a[i][j] );
      else
      a[i][j]=0;
    }
  }
  for(i=0;i<column;i++)
  {
    for(j=0;j<row;j++)
    {
      // if(i==j)
      // printf("%d\n",a[i][j] );
      // else if(i-j==1)
      // printf("%d\n",a[i][j] );
      // else if (i-j==-1)
      // printf("%d\n",a[i][j] );
      printf("%d",a[i][j] );

    }
    printf("\n" );
  }

}
