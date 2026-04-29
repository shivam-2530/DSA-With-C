// wap read five number display the sum and using double link list 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int num;
    struct node *next;
};

int ch,ch1,count=0,i,sum=0;
char c;
struct node *ptr,*ptr1,*start,*end;

void create();
void display();

int main()
{
    back:
    printf("\nPress 1 for create\n");
    printf("Press 2 for display\n");
    printf("Press 3 for end the program\n");
    printf("select amy one\n");
    scanf("%d",&ch);
    system("cls");
    switch (ch)
    {
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        return 0;
        break;
    default:
    printf("Wrong choice\n");
        break;
    }
    goto back;
}

void create()
{
    start=(struct node*)malloc(1*sizeof(struct node));
    ptr=start;
    ptr->prev=NULL;
    back:
    printf("\nEnter one number\n");
    scanf("%d",&ptr->num);
    count++;
    printf("press y for creating new node\n");
    c=getche();
    if (c=='y')
    {
        ptr1=ptr;
        ptr->next=(struct node*)malloc(1*sizeof(struct node));
        ptr=ptr->next;
        ptr->prev=ptr1;
        goto back;
    }
    else
    {
        ptr->next=NULL;
        end=ptr;
    }
}

void display()
{
    if (count==0)
    {
        printf("No node is created\n");
    }
    else
    {
        printf("press 1 for display first to last node\n");
        printf("press 2 for display last to first node\n");
        scanf("%d",&ch1);
        system("cls");
        switch (ch1)
        {
        case 1:
            {
                ptr=start;
                do
                {
                    printf("the value is - %d\n",ptr->num);
                    sum=sum+ptr->num;
                    ptr=ptr->next;
                } while (ptr->next!=NULL);
                printf("the value is - %d\n",ptr->num);
                sum=sum+ptr->num;
                printf("the sum is = %d\n",sum);
                break;
            }
        case 2:
            {
                ptr=end;
                do
                {
                    printf("the value is - %d\n",ptr->num);
                    sum=sum+ptr->num;
                    ptr=ptr->prev;
                } while (ptr->prev!=NULL);
                printf("the value is - %d\n",ptr->num);
                sum=sum+ptr->num;
                printf("the sum is = %d\n",sum);
                break;
            }
        default:
        printf("wrong choice\n");
            break;
        }
    }
}