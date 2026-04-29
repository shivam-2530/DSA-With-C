#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int k[100],m[100],i,j,front=-1,rear=-1,n,s,se,ch;
char c;

void insert();
void display();
void dele();
void search();

int main()
{
    back:
    printf("\npress 1 for insert value\n");
    printf("press 2 for display value\n");
    printf("press 3 for delete value\n");
    printf("press 4 for search value\n");
    printf("press 5 for end\n");
    printf("select any one\n");
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
        search();
        break;
    case 5:
        return 0;
        break;
    default:
    printf("wrong choice\n");
        break;
    }
    goto back;
}

void insert()
{
    if (front==-1&&rear==-1)
    {
        printf("enter the size of queue\n");
        scanf("%d",&n);
        front=0;
    }
    back:
    if (rear<n-1)
    {
        rear++;
        printf("\nenter the value\n");
        scanf("%d",&k[rear]);
        printf("enter the priority\n");
        scanf("%d",&m[rear]);
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
        printf("\nqueue is full\n");
    }
}

void display()
{
    if (front==-1&&rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("element in queue\n");
        for ( i = 0; i <=rear; i++)
        {
            for ( j = i+1; j <=rear; j++)
            {
                if (m[i]>m[j])
                {
                    s=k[i];
                    k[i]=k[j];
                    k[j]=s;
                    s=m[i];
                    m[i]=m[j];
                    m[j]=s;
                }
            }
        }
        for ( i = 0; i <= rear; i++)
        {
            printf("%d (priority %d)\n",k[i],m[i]);
        }
    }
}

void dele() 
{
    if (front==-1 && rear==-1)
    {
        printf("There is no any value\n");
    }
    else
    {
        for ( i = 0; i <=rear; i++)
        {
            for ( j = i+1; j <=rear; j++)
            {
                if (k[i]>k[j])
                {
                    s=k[i];
                    k[i]=k[j];
                    k[j]=s;
                    s=m[i];
                    m[i]=m[j];
                    m[j]=s;
                }
            }
        }
        back:
        printf("\n");
        printf("Delete = %d\n",k[front]);
        for ( i = front; i < rear; i++)
        {
            k[i]=k[i+1];
            m[i]=m[i+1];
        }
        rear--;
        printf("press y for continue\n");
        c=getche();
        if (c=='y')
        {
            if (rear>=front)
            {
                goto back;
            }
            else
            {
                printf("\nQueue is empty\n");
                front=rear=-1;
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
}

void search()
{
    int found=0;
    if (front==-1&&rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("enter number\n");
        scanf("%d",&se);
        for ( i = front; i <=rear; i++)
        {
            if (k[i]==se)
            {
                printf("Number is present at postion %d\n",i+1);
                found=1;
                break;
            }
        }
        if (found==0)
        {
            printf("Number is not prsent\n");
        }
    }
}