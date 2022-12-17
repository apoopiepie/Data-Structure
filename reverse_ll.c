#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

static void reverse(struct Node** head_og)
{
	struct Node* prev = NULL;
	struct Node* current = *head_og;
	struct Node* next = NULL;
	while (current != NULL) {
		
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	*head_og = prev;
}


void push(struct Node** head_og, int new_data)
{
	struct Node* n_node
		= (struct Node*)malloc(sizeof(struct Node));
	n_node->data = new_data;
	n_node->next = (*head_og);
	(*head_og) = n_node;
}


void printll(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 11);
	push(&head, 22);
	push(&head, 33);
	push(&head, 44);

	printf("Original linked list\n");
	printll(head);
	reverse(&head);
	printf("\nReversed \n");
	printll(head);
	getchar();
}
