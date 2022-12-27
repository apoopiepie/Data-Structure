
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* sorted = NULL;

void push(int val)
{
	struct node* newnode
		= (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = head;
	head = newnode;
}

void insort(struct node* newnode)
{
	if (sorted == NULL || sorted->data >= newnode->data) {
		newnode->next = sorted;
		sorted = newnode;
	}
	else {
		struct node* current = sorted;
		while (current->next != NULL
			&& current->next->data < newnode->data) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}


void insertsort()
{

	struct node* current = head;

	while (current != NULL) {

		struct node* next = current->next;

		insort(current);

		current = next;
	}
	head = sorted;
}

void prtlist(struct node* head)
{
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL");
}

int main()
{

	push(25);
	push(26);
	push(4);
	push(9);
	push(99);

	insertsort(head);

	printf("Sorted list:\n");
	prtlist(head);
}
