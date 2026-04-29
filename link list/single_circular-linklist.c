// wap perform the all task with single circular link list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

int ch,i,count=0,p;
char c;
struct node *ptr, *ptr1, *start, *newnode;

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
    printf("Press 5 for End the program\n");
    printf("Select any one\n");
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
    start=(struct node*)malloc(1*sizeof(struct node));
    ptr=start;
    create_again:
    printf("\nEnter one number\n");
    scanf("%d",&ptr->num);
    count++;
    printf("press y for continue\n");
    c=getche();
    if (c=='y')
    {
        ptr1=ptr;
        ptr=(struct node*)malloc(1*sizeof(struct node));
        ptr1->next=ptr;
        goto create_again;
    }
    else
    {
        ptr->next=start;
    }
}

void display()
{
    if (count==0)
    {
        printf("No any node is created\n");
    }
    else
    {
        ptr=start;
        do
        {
            printf("%d\n",ptr->num);
            ptr=ptr->next;
        } while (ptr->next!=start);
        printf("%d",ptr->num);
    }
}

void insert()
{
    if (count==0)
    {
        printf("No any node is created\n");
    }
    else
    {
        to_insert:
        printf("\nPress 1 for insert at first\n");
        printf("Press 2 for insert at middle\n");
        printf("Press 3 for insert at last\n");
        printf("Press 4 for exit\n");
        printf("Select any one\n");
        scanf("%d",&ch);
        system("cls");
        switch (ch)
        {
        case 1:
            {
                ptr=start;
                start=(struct node*)malloc(1*sizeof(struct node));
                printf("Enter one number\n");
                scanf("%d",&start->num);
                start->next=ptr;
                count++;
                ptr1=ptr;
                ptr=start;
                do
                {
                    ptr=ptr->next;
                } while (ptr->next!=ptr1);
                ptr->next=start;
                break;
            }
        case 2:
            {
                printf("Enter position to insert\n");
                scanf("%d",&p);
                if (p==1 || p==count ||p>count)
                {
                    printf("Plz enter middle postion\n");
                    goto to_insert;
                }
                else
                {
                    ptr=start;
                    for ( i = 1; i < p; i++)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                    }
                    newnode=(struct node*)malloc(1*sizeof(struct node));
                    ptr1->next=newnode;
                    printf("Enter one number\n");
                    scanf("%d",&newnode->num);
                    newnode->next=ptr;
                    count++;
                }
                break;
            }
        case 3:
            {
                ptr=start;
                while (ptr->next!=start)
                {
                    ptr=ptr->next;
                }
                ptr1=ptr;
                ptr=(struct node*)malloc(1*sizeof(struct node));
                ptr1->next=ptr;
                printf("Enter one number\n");
                scanf("%d",&ptr->num);
                ptr->next=start;
                break;
            }
        default:
        printf("Wrong choise\n");
        goto to_insert;
        break;
        case 4:
        break;
        }
    }
}

void dele()
{
    if (count==0)
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
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
            case 1:
            {
                ptr=start;
                start=ptr->next;
                ptr1=ptr;
                do
                {
                    ptr=ptr->next;
                } while (ptr->next!=ptr1);
                ptr->next=start;
                printf("delete value = %d\n",ptr1->num);
                free(ptr1);
                count--;
                break;
            }
            case 2:
            {
                printf("\nEnter position\n");
                scanf("%d",&p);
                if (p==1||p==count||p>count)
                {
                    printf("plz enter middle node\n");
                    goto back;
                }
                else
                {
                    ptr=start;
                    for ( i = 1; i < p; i++)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                    }
                    ptr1->next=ptr->next;
                    printf("delete value = %d\n",ptr->num);
                    free(ptr);
                    count--;
                }
                break;
            }
            case 3:
            {
                ptr=start;
                while (ptr->next!=start)
                {
                    ptr1=ptr;
                    ptr=ptr->next;
                }
                ptr1->next=start;
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