#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int num;
    struct node *next;
};

struct node *ptr,*ptr1,*start,*end;
int max=-32767,i,ch;
int main()
{
    back:
    printf("\nPress 1 for first to last\n");
    printf("Press 2 for last to first\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        {
            start=(struct node*)malloc(1*sizeof(struct node));
            ptr=start;
            ptr->prev=NULL;
            for ( i = 0; i < 5; i++)
            {
                printf("Enter one number\n");
                scanf("%d",&ptr->num);
                ptr1=ptr;
                ptr=(struct node*)malloc(1*sizeof(struct node));
                ptr1->next=ptr;
                ptr->prev=ptr1;
                if (ptr->num>max)
                {
                    max=ptr->num;
                }
                ptr=ptr->next;
            }
            
            break;
        }
    
    default:
        break;
    }
    goto back;
}