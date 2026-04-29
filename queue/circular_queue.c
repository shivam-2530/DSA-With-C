// WAP from the all task with cirular queue , insert display delete and search.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int k[100], front = -1, rear = -1, i, n, s, ch;
char c;

void insert();
void display();
void dele();
void search();

int main()
{
back:
    printf("\nPress 1 for insert value\n");
    printf("Press 2 for display value\n");
    printf("Press 3 for delete value\n");
    printf("Press 4 for search value\n");
    printf("Press 5 for end\n");
    printf("Select any one\n");
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
        printf("Wrong choise\n");
        break;
    }
    goto back;
}

void insert()
{
    if (front == -1 && rear == -1)
    {
        printf("Enter how many number you have\n");
        scanf("%d", &n);
        front = 0;
    }
back:
    if (rear < n - 1)
    {
        printf("\nEnter the one value\n");
        rear++;
        scanf("%d", &k[rear]);
        printf("Press y for insert the value again\n");
        c = getche();
        if (c == 'y')
        {
            if (front < n - 1)
            {
                goto back;
            }
            else
            {
                printf("\nQueue is full\n");
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    if (front > 0 && rear == n - 1)
    {
        rear = 0;
    back1:
        printf("\nEnter one number\n");
        scanf("%d", &k[rear]);
        printf("Press y for insert the value again\n");
        c = getche();
        if (c == 'y')
        {
            if (rear < front - 1)
            {
                rear++;
                goto back1;
            }
            else
            {
                printf("\nQueue is full\n");
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    if (front > 0 && rear < front - 1)
    {
    back2:
        rear++;
        printf("\nEnter one number\n");
        scanf("%d", &k[rear]);
        printf("Press y for continue\n");
        c = getche();
        if (c == 'y')
        {
            if (rear < front - 1)
            {
                rear++;
                goto back2;
            }
            else
            {
                printf("\nQueue is full\n");
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    if (front > 0 && (rear < n - 1 && rear > front))
    {
    back3:
        printf("\nEnter one number\n");
        scanf("%d", &k[rear]);
        printf("Press y for continue\n");
        c = getche();
        if (c == 'y')
        {
            if (rear < front - 1)
            {
                rear++;
                goto back3;
            }
            else
            {
                goto back1;
            }
        }
        else
        {
            printf("\nThanks\n");
        }
    }
    if (rear == n - 1)
    {
        printf("\nQueue is full\n");
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d\n", k[i]);
            }
        }
        if (rear < front)
        {
            for (i = front; i <= n - 1; i++)
            {
                printf("%d\n", k[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d\n", k[i]);
            }
        }
    }
}

void dele()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
back:
    if (rear >= front)
    {
        printf("\ndelete value = %d\n", k[front]);
        front++;
        printf("press y for deleting next\n");
        c = getche();
        if (c == 'y')
        {
            if (front <= rear)
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
    if (front > rear)
    {
    back2:
        printf("\ndelete value = %d\n", k[front]);
        front++;
        printf("press y for deleting next value\n");
        c = getche();
        if (c == 'y')
        {
            if (front <= n - 1)
            {
                goto back2;
            }
            else
            {
                front = 0;
            back3:
                printf("\ndelted value = %d\n", k[front]);
                front++;
                printf("press y for deleting next\n");
                c = getche();
                if (c == 'y')
                {
                    if (front <= rear)
                    {
                        goto back3;
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
        }
    }
}

void search()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int found = 0;
        printf("Enter one number\n");
        scanf("%d", &s);
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
            {
                if (k[i] == s)
                {
                    printf("Number is present = %d position\n", i + 1);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("Number is not present\n");
            }
        }
        if (front > rear)
        {
            for (i = front; i <= n - 1; i++)
            {
                if (k[i] == s)
                {
                    printf("Number is present = %d position\n", i + 1);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("Number is not present\n");
            }
        }
    }
}