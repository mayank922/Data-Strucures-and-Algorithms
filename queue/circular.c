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
void display(struct queue *qu)
{
  int i=qu->front+1;

 do
 {

 printf("%d ",qu->q[i]);
 i=(i+1)%qu->size;
}while(i!=(qu->rear+1)%qu->size);

 printf("\n");
}
int main()
{
  struct queue *qu;
  qu=(struct queue *)malloc(sizeof(struct queue));
  printf("enter size\n");
  scanf("%d",&qu->size );
  qu->front=qu->rear=0;
  qu->q=(int *)malloc(qu->size*sizeof(int));
  enqueue(qu,5);
  enqueue(qu,6);
  enqueue(qu,7);
  enqueue(qu,8);
  enqueue(qu,9);
  enqueue(qu,10);
  display(qu);
  printf("%d",dequeue(qu) );




}
