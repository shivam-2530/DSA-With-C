// wap perform the all task with double link list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int num;
    struct node *next;
};

int ch, count = 0, i, p, ps;
char c;
struct node *ptr, *ptr1, *ptr2, *start, *end;

void create();
void display();
void insert();
void dele();

int main()
{
back:
    printf("\nPress 1 for create\n");
    printf("Press 2 for display\n");
    printf("Press 3 for insert\n");
    printf("Press 4 for delete\n");
    printf("Press 5 for end the program\n");
    printf("select amy one\n");
    scanf("%d", &ch);
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
        insert();
        break;
    case 4:
        dele();
        break;
    case 5:
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
    start = (struct node *)malloc(1 * sizeof(struct node));
    ptr = start;
    ptr->prev = NULL;
back:
    printf("\nEnter one number\n");
    scanf("%d", &ptr->num);
    count++;
    printf("press y for creating new node\n");
    c = getche();
    if (c == 'y')
    {
        ptr1 = ptr;
        ptr= (struct node *)malloc(1 * sizeof(struct node));
        ptr1->next=ptr;
        ptr->prev = ptr1;
        goto back;
    }
    else
    {
        ptr->next = NULL;
        end = ptr;
    }
}

void display()
{
    if (count == 0)
    {
        printf("No any node is created\n");
    }
    else
    {
        printf("press 1 for display first to last node\n");
        printf("press 2 for display last to first node\n");
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
        case 1:
        {
            ptr = start;
            do
            {
                printf("the value is - %d\n", ptr->num);
                ptr = ptr->next;
            } while (ptr->next != NULL);
            printf("the value is - %d\n", ptr->num);
            break;
        }
        case 2:
        {
            ptr = end;
            do
            {
                printf("the value is - %d\n", ptr->num);
                ptr = ptr->prev;
            } while (ptr->prev != NULL);
            printf("the value is - %d\n", ptr->num);
            break;
        }
        default:
            printf("wrong choice\n");
            break;
        }
    }
}

void insert()
{
    if (count == 0)
    {
        printf("no any node is created\n");
    }
    else
    {
    back:
        printf("\n1 for insert at first\n");
        printf("2 for insert at middle\n");
        printf("3 for insert at last\n");
        printf("4 for exit\n");
        printf("select any one\n");
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
        case 1:
        {
            ptr1 = start;
            start = (struct node *)malloc(1 * sizeof(struct node));
            ptr = start;
            ptr1->prev = ptr;
            ptr->prev = NULL;
            printf("enter one number\n");
            scanf("%d", &ptr->num);
            ptr->next = ptr1;
            count++;
            break;
        }
        case 2:
        {
            printf("Enter the position\n");
            scanf("%d", &p);
            if (p == 1 || p == count)
            {
                printf("plz enter middle position\n");
                goto back;
            }
            else
            {
                ptr = start;
                for (i = 1; i < p; i++)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                ptr2 = (struct node *)malloc(1 * sizeof(struct node));
                ptr1->next = ptr2;
                ptr2->prev = ptr1;
                ptr2->next = ptr;
                ptr->prev=ptr2;
                printf("Enter one number\n");
                scanf("%d", &ptr2->num);
                count++;
            }
            break;
        }
        case 3:
        {
            ptr = end;
            end = (struct node *)malloc(1 * sizeof(struct node));
            end->prev = ptr;
            ptr->next = end;
            end->next = NULL;
            printf("Enter one number\n");
            scanf("%d", &end->num);
            count++;
            break;
        }
        default:
            printf("wrong choice\n");
            goto back;
            break;

        case 4:
            printf("");
            break;
        }
    }
}

void dele()
{
    if (count == 0)
    {
        printf("No any node is created\n");
    }
    else
    {
    back:
        printf("\n1 for delete at first\n");
        printf("2 for delete at middle\n");
        printf("3 for delete at last\n");
        printf("4 for exit\n");
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
        case 1:
        {
            ptr = start;
            start = ptr->next;
            start->prev = NULL;
            printf("delete value = %d\n", ptr->num);
            free(ptr);
            count--;
        }
        break;
        case 2:
        {
            printf("Enter the position\n");
            scanf("%d", &ps);
            if (ps==1||ps==count)
            {
                printf("plz enter middle node\n");
                goto back;
            }
            else
            {
                ptr=start;
                for ( i = 1; i < ps; i++)
                {
                    ptr1=ptr;
                    ptr=ptr->next;
                }
                ptr1->next=ptr->next;
                ptr1=ptr1->next;
                ptr1->prev=ptr->prev;
                printf("delete value = %d\n", ptr->num);
                free(ptr);
                count--;
            }
            break;
        }
        case 3:
        {
            ptr=end;
            end=ptr->prev;
            end->next=NULL;
            printf("delete value = %d\n", ptr->num);
            free(ptr);
            count--;
            break;
        }
        default:
        printf("wrong choice\n");
            goto back;
            break;

        case 4:
        printf("");
        break;
        }
    }
}