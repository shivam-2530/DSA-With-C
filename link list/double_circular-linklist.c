// wap perform the all task with double circular link list.  
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int num;
    struct node *next;
};

struct node *ptr,*ptr1,*start,*newnode, *end;

int count=0,ch,p,i;
char c;

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
    printf("select any one\n");
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
    back:
    printf("\nEnter one number\n");
    scanf("%d",&ptr->num);
    count++;
    printf("press y for continue\n");
    c=getche();
    if (c=='y')
    {
        ptr1=ptr;
        ptr=(struct node*)malloc(1*sizeof(struct node));
        ptr->prev=ptr1;
        ptr1->next=ptr;
        goto back;
    }
    else
    {
        ptr->next=start;
        start->prev=ptr;
        end=ptr;
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
        printf("Press 1 for display first node to last node\n");
        printf("Press 2 for display last node to first node\n");
        scanf("%d",&ch);
        system("cls");
        switch (ch)
        {
        case 1:
            {
                ptr=start;
                do
                {
                    printf("%d\n",ptr->num);
                    ptr=ptr->next;
                } while (ptr->next!=start);
                printf("%d\n",ptr->num);
                break;
            }
        case 2:
            {
                ptr=end;
                do
                {
                    printf("%d\n",ptr->num);
                    ptr=ptr->prev;
                } while (ptr->prev!=end);
                printf("%d\n",ptr->num);
                break;
            }
        default:
        printf("Wrong choise\n");
            break;
        }
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
        back:
        printf("\nPress 1 for insert at first\n");
        printf("Press 2 for insert at middle\n");
        printf("press 3 for insert at last\n");
        printf("Press 4 for exit\n");
        scanf("select any one\n");
        scanf("%d",&ch);
        system("cls");
        switch (ch)
        {
        case 1:
            {
                ptr=start;
                start=(struct node*)malloc(1*sizeof(struct node));
                start->next=ptr;
                ptr->prev=start;
                printf("Enter one number\n");
                scanf("%d",&start->num);
                count++;
                start->prev=end;
                end->next=start;
                break;
            }
        case 2:
            {
                ptr=start;
                printf("Enter middle position\n");
                scanf("%d",&p);
                if (p==1||p==count||p>count)
                {
                    printf("Plz enter middle position\n");
                    goto back;
                }
                else
                {
                    for ( i = 1; i < p; i++)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                    }
                    newnode=(struct node*)malloc(1*sizeof(struct node));
                    newnode->prev=ptr1;
                    printf("Enter one number\n");
                    scanf("%d",&newnode->num);
                    newnode->next=ptr;
                    ptr1->next=newnode;
                    ptr->prev=newnode;
                    count++;
                }
                break;
            }
        case 3:
            {
                ptr=end;
                end=(struct node*)malloc(1*sizeof(struct node));
                end->prev=ptr;
                start->prev=end;
                ptr->next=end;
                printf("Enter one number\n");
                scanf("%d",&end->num);
                end->next=start;
                count++;
                break;
            }
        default:
        printf("Wrong choise\n");
        goto back;
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
        printf("\nPress 1 for delete at first\n");
        printf("Press 2 for delete at middle\n");
        printf("Press 3 for delete at last\n");
        printf("Press 4 for exit\n");
        printf("select any one\n");
        scanf("%d",&ch);
        system("cls");
        switch (ch)
        {
        case 1:
            {
                ptr=start;
                start=ptr->next;
                start->prev=end;
                end->next=start;
                printf("delete value = %d\n",ptr->num);
                free(ptr);
                count--;
                break;
            }
        case 2:
            {
                ptr=start;
                printf("Enter middle position\n");
                scanf("%d",&p);
                if (p==0||p==count||p>count)
                {
                    printf("Plz enter middle position\n");
                    goto back;
                }
                else
                {
                    for ( i = 0; i < p; i++)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                    }
                    ptr1->next=ptr->next;
                    ptr1=ptr1->next;
                    ptr1->prev=ptr->prev;
                    printf("delete value = %d\n",ptr->num);
                    free(ptr);
                    count--;
                }
                break;
            }
        case 3:
            {
                ptr=end;
                ptr1=ptr->prev;
                ptr1->next=start;
                start->prev=ptr1;
                printf("delete value = %d\n",ptr->num);
                free(ptr);
                count--;
                break;
            }
        default:
        printf("Wrong choise\n");
            break;
        }
    }
}