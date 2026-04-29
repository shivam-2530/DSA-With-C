#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int num;
    struct node *right;
};

struct node *ptr, *ptr1, *start, *end;
int ch,count=0;
char c;
void insert();
void display();
void dele();

int main()
{
    back:
    printf("\npress 1 for insert\n");
    printf("press 2 for display\n");
    printf("press 3 for delete\n");
    printf("press 4 for End\n");
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
        return 0;
        break;
        default:
        printf("Wrong choice\n");
    }
    goto back;
}

void insert()
{
    start=(struct node*)malloc(1*sizeof(struct node));
    ptr=start;
    printf("Enter one number\n");
    scanf("%d",&ptr->num);
    count++;
    start->right=start->left=NULL;
    back:
    printf("press y for continue\n");
    scanf(" %c",&c);
    if (c=='y')
    {
        ptr1=ptr;
        ptr=(struct node*)malloc(1*sizeof(struct node));
        printf("\nEnter one number\n");
        scanf("%d",&ptr->num);
        count++;
        do
        {
        if (start->num < ptr->num)
        {
            ptr1->right=ptr;
        }
        else
        {
            ptr1->left=ptr;
        }
        } while (ptr1->right!=NULL&&ptr1->left!=NULL);
        goto back;
    }
    
}