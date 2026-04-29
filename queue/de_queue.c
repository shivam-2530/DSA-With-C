// wap from tha all task with deque , insert, display, delete and search
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int k[100], n, i, s, ch, rear = -1, front = -1, ch2;
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
    scanf("%d", &ch);
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
    if (front == -1 && rear == -1)
    {
        printf("press 1 for insert from front\n");
        printf("press 2 for insert from rear\n");
        scanf("%d", &ch2);
        system("cls");
        if (ch2 == 1)
        {
            if (front == -1 && rear == -1)
            {
                printf("enter the size of queue\n");
                scanf("%d", &n);
                front = 0;
            }
        back:
            if (rear < n - 1)
            {
                printf("\nenter the value\n");
                rear++;
                scanf("%d", &k[rear]);
                printf("press y for continue\n");
                c = getche();
                if (c == 'y')
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
                printf("\nQueue is full\n");
            }
        }
        if (ch2 == 2)
        {
            if (front == -1 && rear == -1)
            {
                printf("Enter the size of queue\n");
                scanf("%d", &n);
                front = n - 1;
                rear = n;
            }
        reverse:
            if (rear > 0)
            {
                printf("\nEnter the value\n");
                rear--;
                scanf("%d", &k[rear]);
                printf("press y for continue\n");
                c = getche();
                if (c == 'y')
                {
                    goto reverse;
                }
                else
                {
                    printf("\nThanks\n");
                }
            }
            else
            {
                printf("\nQueue is full\n");
            }
        }
    }
    else
    {
        if (ch2 == 1)
        {
            goto back;
        }
        if (ch2 == 2)
        {
            goto reverse;
        }
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("There is no any value\n");
    }
    if (ch2 == 1)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", k[i]);
        }
    }
    else
    {
        for (i = front; i >= rear; i--)
        {
            printf("%d\n", k[i]);
        }
    }
}

void dele()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    if (ch2 == 1)
    {
    back:
        printf("\ndelete value = %d\n", k[front]);
        for (i = 0; i <= rear; i++)
        {
            k[i] = k[i + 1];
        }
        rear--;
        printf("press y for continue\n");
        c = getche();
        if (c == 'y')
        {
            if (rear >= front)
            {
                goto back;
            }
            else
            {
                printf("\nQueue is empty\n");
                front = rear = -1;
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    else
    {
    reverse:
        printf("\ndelete value = %d\n", k[front]);
        for (i = front; i > rear; i--)
        {
            k[i] = k[i - 1];
        }
        rear++;
        printf("press y for continue\n");
        c = getche();
        if (c == 'y')
        {
            if (rear <= front)
            {
                goto reverse;
            }
            else
            {
                printf("\nqueue is empty\n");
                front = rear = -1;
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
    int found = 0;
    if (front == -1 && rear == -1)
    {
        printf("There is no any value\n");
    }
    else
    {
        printf("Enter one number\n");
        scanf("%d", &s);
    }
    if (ch2 == 1)
    {
        for (i = 0; i <= rear; i++)
        {
            if (k[i] == s)
            {
                printf("number is present = %d poition\n", i + 1);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("number is not present\n");
        }
    }
    else
    {
        for (i = 0; i >= rear; i--)
        {
            if (k[i] == s)
            {
                printf("number is present = %d poition\n", i + 1);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("number is not present\n");
        }
    }
}