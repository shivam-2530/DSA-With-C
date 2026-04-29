#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack
{
    int num;
    struct stack *prev;
};

struct stack *ptr,*top=NULL,*ptr1;
int ch;
char c;

void insert();
void display();
void dele();

int main()
{
    back:
    printf("\nPress 1 for insert\n");
    printf("Press 2 for display\n");
    printf("Press 3 for delete\n");
    printf("Press 4 for delete the program\n");
    printf("Select anyone\n");
    scanf("%d",&ch);
    system("cls");
    switch (ch)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        dele();
        break;
    case 4:
        return 0;
        break;
    default:
    printf("Wrong choice\n");
        break;
    }
    goto back;
}

void insert()
{
    back:
    ptr=(struct stack*)malloc(1*sizeof(struct stack));
    if (ptr==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Enter one number\n");
        scanf("%d",&ptr->num);
        ptr->prev=top;
        top=ptr;
        printf("press y for continue\n");
        scanf(" %c",&c);
        if (c=='y')
        {
            goto back;
        }
        else
        {
            printf("thanks\n");
        }
    } 
}

void display()
{
    if (top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        ptr=top;
        do
        {
            printf("%d\n",ptr->num);
            ptr=ptr->prev;
        }while (ptr->prev!=NULL);
        printf("%d\n",ptr->num);
    }   
}

void dele()
{
    if (top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        back:
        ptr=top;
        top=ptr->prev;
        printf("delete value = %d\n",ptr->num);
        free(ptr);
    }
}