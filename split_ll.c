#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
};

void splitList(struct Node *head, struct Node **head1,
											struct Node **head2)
{
struct Node *first_ptr = head;
struct Node *sec_ptr = head;

if(head == NULL)
	return;

// sec_ptr-> next becomes head for odd nodes and sec-ptr->next->next becomes head for even nodes 

while(sec_ptr->next != head &&
		sec_ptr->next->next != head)
{
	sec_ptr = sec_ptr->next->next;
	first_ptr = first_ptr->next;
}

if(sec_ptr->next->next == head)
	sec_ptr = sec_ptr->next;	
	
*head1 = head;	

if(head->next != head)
	*head2 = first_ptr->next;
	
// we now make the second half circular
sec_ptr->next = first_ptr->next;
	
// now first half circular
first_ptr->next = head;	
}

 // function to add a node to the beginning of the linked list

void push(struct Node **head_ref, int data)
{
struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
struct Node *temp = *head_ref;
ptr1->data = data;
ptr1->next = *head_ref;
	

if(*head_ref != NULL)
{
	while(temp->next != *head_ref)
	temp = temp->next;		
	temp->next = ptr1;
}
else
	ptr1->next = ptr1; 

*head_ref = ptr1;	
}

// to print nodes ion the list
void printList(struct Node *head)
{
struct Node *temp = head;
if(head != NULL)
{
	printf("\n");
	do {
	printf("%d ", temp->data);
	temp = temp->next;
	} while(temp != head);
}
}

// now to execute above written code
int main()
{
int list_size, i;
	

struct Node *head = NULL;
struct Node *head1 = NULL;
struct Node *head2 = NULL;


push(&head, 10);
push(&head, 20);
push(&head, 55);
push(&head, 17);

printf("OriginalLinked List");
printList(head);	

splitList(head, &head1, &head2);

printf("\nFirst Linked List");
printList(head1);

printf("\nSecond Linked List");
printList(head2);
	
getchar();
return 0;
}
