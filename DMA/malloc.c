// WAP read 5 number and display using malloc. 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, i;
    p = (int *)malloc(5 * sizeof(int));
    printf("enter five number\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
    return 0;
}