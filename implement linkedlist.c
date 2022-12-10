#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i, n, item;
    struct node *p, *q, *headp;

    printf("Enter the total number of nodes ");
    scanf("%d", &n);

    printf("Enter value of head node ");    //head node is first created seperately
    scanf("%d", &item);

    q = (struct node *) malloc(sizeof(struct node));   //allocating memory to the node
    q ->data = item;
    q ->next = NULL;

    headp = q;
    p = headp;   //used to link the nodes

    for(i = 1; i < n; i++)
    {
     printf("Enter value of next node ");
     scanf("%d", &item);

     q = (struct node *) malloc(sizeof(struct node));
     q ->data = item;
     q ->next = NULL;
    }

    // now we get the pointer p to point to the next node (i.e. q)

    p ->next = q;
    p = p->next;   // pointer p then goes to the next node (iterative process)


    printf("\n");
    p = headp;
    while(p!=NULL)
    {
     printf("\t %d",p->data);
     p = p->next;
    }
return 0;

}    
