#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int k[100],n,top=-1,i,ch;
char c;

void push();
void display();
void delete();

int main()
{
    back:
    printf("\npress 1 for insert elements  into stack\n");
    printf("press 2 for display elements  into stack\n");
    printf("press 3 for delete elements  into stack\n");
    printf("press 4 for End\n");
    printf("select any one\n");
    scanf("%d",&ch);
    system("cls");
    switch (ch)
    {
    case 1:
        push();
        break;
    case 2:
        display();
        break;
    case 3:
        delete();
        break;
    case 4:
        return 0;
        break;
    default:
        printf("plz check your select case not match\n");
        break;
    }
    goto back;
}

void push()
{
    if (top==-1)
    {
        printf("how many number you have\n");
        scanf("%d",&n);
    }
    back:
    if (top<n-1)
    {
        printf("\nenter one number\n");
        top++;
        scanf("%d",&k[top]);
        printf("press y for continue\n");
        c=getche();
        if (c=='y')
        {
            goto back;
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    else
    {
        printf("\nstcak is overflow\n");
    }
}

void display()
{
    if (top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("elements of stack\n");
        for ( i = top; i>=0; i--)
        {
            printf("%d\n",k[i]);
        }
    }
}

void delete()
{
    if (top==-1)
    {
        printf("stack is underflow\n");
    }
    back:
    if (top>=0)
    {
        printf("\ndelete element is..%d\n",k[top]);
        top--;
        printf("press y for continue\n");
        c=getche();
        if (c=='y')
        {
            goto back;
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    else
    {
        printf("now there is no any value in stack\n");
    }
} 