// wap read the all task with linear queue.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int k[100], n, i, front = -1, rear = -1, ch, r, p=0;
char c;

void insert();
void display();
void dele();
void search();

int main()
{
    back:
    printf("\npress 1 for insert value into queue\n");
    printf("press 2 for display value into queue\n");
    printf("press 3 for delete value into queue\n");
    printf("press 4 for search in queue\n");
    printf("press 5 for End\n");
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
        printf("How many number you have\n");
        scanf("%d", &n);
        front = 0;
    }
back:
    if (rear < n - 1)
    {
        printf("\nEnter one number\n");
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
        printf("\nqueue is full\n");
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("there is no value\n");
    }
    else
    {
        printf("elemnts of queue\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", k[i]);
        }
    }
}

void dele()
{
    if (front == -1 && rear == -1)
    {
        printf("there is no value\n");
    }
back:
    if (rear >= front)
    {
        printf("\ndelete elemnt is %d\n", k[front]);
        for (i = 0; i < rear; i++)
        {
            k[i] = k[i + 1];
        }
        rear--;
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
        printf("\nqueue is empty\n");
        front = rear = -1;
    }
}

void search()
{
    if (front == -1 && rear == -1)
    {
        printf("there is no any value\n");
    }
    else
    {
    printf("Enter one number\n");
    scanf("%d", &r);
    for (i = front; i <= rear; i++)
    {
        if (k[i] == r)
        {
            p++;
        }
    }
    if (p>0)
    {
        printf("num is found %d time\n",p);
    }
    else
    {
        printf("num is not found\n");
    }
}
}
