#include "stdio.h"
#include "stdlib.h"
struct element {
  int i;
  int j;
  int x;
};
struct sparse {
  int m;
  int n;
  int num;
  struct element *e;
};
int create(struct sparse *s)
{
  int g=0;
  printf("enter dimensions\n" );
  scanf("%d%d",&s->m,&s->n );
  printf("enter  num of non zero elemts\n" );
  scanf("%d",&s->num );
  printf("enter the elemntents\n" );
  s->e=(struct element *)malloc(s->num*sizeof(struct element));  //creating array of elements
  for(g=0;g<s->num;g++)
  {
    scanf("%d%d%d",&s->e[g].i,&s->e[g].j,s->e[g].x );
  }

}

void display(struct sparse s) //will not take *s because it will not change anything so call by value is suff
{
  int i,j,k=0;
  for(i=0;i<s.m;i++)
  {
    for (j = 0; j <s.n; j++)
    {
      if(i==s.e[k].i && j==s.e[k].j)
      printf("%d",s.e[k++].x );
      else
      printf("0 " );
    }
    printf("\n" );
  }
}
 int main()
 {
   struct sparse s;
   create(&s);
   display(s);
   return 0;
 }
