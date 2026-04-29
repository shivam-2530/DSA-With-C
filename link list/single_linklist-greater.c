// wap read five no and find greater.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};
int max=-32767,i;
struct node *start, *ptr;

int main()
{
    start=(struct node*)malloc(1*sizeof(struct node));
    ptr=start;
    for (i = 1; i <= 5; i++)
    {
        printf("Enter one num\n");
        scanf("%d",&ptr->num);
        ptr->next=(struct node*)malloc(1*sizeof(struct node));
        if (ptr->num>max)
        {
            max=ptr->num;
        }
        ptr=ptr->next;
    }
    printf("greater = %d\n",max);
}
