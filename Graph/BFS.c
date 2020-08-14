#include "stdio.h"
#include "stdlib.h"







         struct queue
         {
           int size;
           int front;
           int rear;
           int *q;
         };


         void enqueue(struct queue *qu,int x)
         {
           if((qu->rear+1)%qu->size==qu->front)
           {
             printf("queue is full" );
           }
           else
           {
             qu->rear=(qu->rear+1)%qu->size;
             qu->q[qu->rear]=x;
           }

         }
         int dequeue(struct queue *qu)
         {
           int x=-1;
           if(qu->front==qu->rear)
           {
             printf("empty queue\n" );
           }
           else
         {
           qu->front=(qu->front+1)%qu->size;
           x=qu->q[qu->front];
         }
         return x;
         }





         void BFS( int g[][7],int start,int n )
         {
           int i= start,j;
           int visited[7]={0};
           printf("%d ",i );
           struct queue *qu;
           qu=(struct queue *)malloc(sizeof(struct queue));
           qu->front=qu->rear=0;
           qu->q=(int *)malloc(qu->size*sizeof(int));
           visited[i]=1;
           enqueue(qu,i);
           while(qu->front!=qu->rear)
           {
             i=dequeue(qu);
             for(j=1;j<n;j++)
             {
               if(g[i][j]==1 && visited[j]==0)
               {
                 printf("%d ", j);
                 visited[j]=1;
                 enqueue(qu,j);
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


                  BFS(d,4,7);
         return 0;

           }
