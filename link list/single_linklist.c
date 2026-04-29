// write the code to perform the all task with singal link list such as create, display, insert and delete.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};
int c = 0, ch, count = 0, ch1, ch2, p, i, ps;
char s;
struct node *start, *ptr, *ptr1;

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
    printf("Press 5 for end\n");
    printf("select any one\n");
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
        printf("Wrong choise\n");
        break;
    }
    goto back;
}

void create()
{
    start = (struct node *)malloc(1 * sizeof(struct node));
    ptr = start;
back:
    printf("\nEnter one number\n");
    scanf("%d", &ptr->num);
    c++;
    printf("press y for continue\n");
    s = getche();
    if (s == 'y')
    {
        ptr->next = (struct node *)malloc(1 * sizeof(struct node));
        ptr = ptr->next;
        goto back;
    }
    else
    {
        ptr->next = NULL;
    }
}

void display()
{
    if (c == 0)
    {
        printf("There is no node\n");
    }
    else
    {
        ptr = start;
        do
        {
            printf("\nvalue = %d\n", ptr->num);
            ptr = ptr->next;
        } while (ptr->next != NULL);
        printf("\nvalue = %d\n", ptr->num);
    }
}

void insert()
{
    back:
    printf("\n1 for insert first\n");
    printf("2 for insert middle\n");
    printf("3 for insert last\n");
    printf("4 for exit\n");
    printf("select any one\n");
    scanf("%d", &ch1);
    system("cls");
    switch (ch1)
    {
    case 1:
    {
        ptr = start;
        start = (struct node *)malloc(1 * sizeof(struct node));
        ptr1 = ptr;
        ptr = start;
        printf("Enter one value\n");
        scanf("%d", &ptr->num);
        ptr->next = ptr1;
        count++;
        break;
    }
    case 2:
    {
        struct node *newnode;
        if (c == 0)
        {
            printf("No any node is created\n");
        }
        else
        {
            printf("Enter the position\n");
            scanf("%d", &p);
            if (p==1||p==count)
            {
                printf("plz enter mid postion\n");
                goto back;
            }
            else
            {

                ptr = start;
                for (i = 1; i < p ; i++)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->next = ptr->next;
                ptr->next = newnode;
                printf("enter one number\n");
                scanf("%d", &newnode->num);
                count++;
            }
        }
        break;
    }
    case 3:
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = (struct node *)malloc(1 * sizeof(struct node));
        ptr = ptr->next;
        printf("enter one number\n");
        scanf("%d", &ptr->num);
        ptr->next = NULL;
        break;
    }
    default:
    printf("Wrong choise\n");
    goto back;
    break;
    case 4:
       printf("");
    }
}

void dele()
{
    if (c==0)
    {
        printf("No any node is created\n");
    }
    else
    {
        back:
        printf("1 for delete first\n");
        printf("2 for delete middle\n");
        printf("3 for delete last\n");
        printf("4 for exit\n");
        printf("select any one\n");
        scanf("%d", &ch2);
        system("cls");
        switch (ch2)
        {
            case 1:
            {
                ptr=start;
                start=ptr->next;
                free(ptr);
                count--;
                break;
            }
            case 2:
            {
                printf("\nEnter position\n");
                scanf("%d",&ps);
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
                    printf("delete value = %d\n",ptr->num);
                    free(ptr);
                    count--;
                    break;
                }
                case 3:
                {
                    ptr=start;
                    while (ptr->next!=NULL)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                    }
                    ptr1->next=NULL;
                    printf("delete value = %d\n",ptr->num);
                    free(ptr);
                    count--;
                    break;
                }
                default:
                printf("Wrong choise\n");
                goto back;
                break;
                case 4:
                printf("");
            }
        }
    }
}