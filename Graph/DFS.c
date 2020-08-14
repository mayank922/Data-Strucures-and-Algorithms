#include "stdio.h"
#include "stdlib.h"


void DFS(int g[][7],int start,int n)
{
  int i=start,j;
  static int visited[7]={0};
 if(visited[i]==0)
 {
   printf("%d ", i);
   visited[i]=1;
   for(j=1;j<n;j++)
   {
     if(g[i][j]==1 && visited[j]==0)
     {
       DFS(g,j,n);
     }
   }
 }




}
int main()
         {
         int d[7][7]={{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0}};


                  DFS(d,1,7);
         return 0;

           }
