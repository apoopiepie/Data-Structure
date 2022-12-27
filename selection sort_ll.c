#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void print_ll(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

// Now to insert a new node at the end of linked list

void n_node(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    // Incase the list is empty 
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Selection sort

void selSort(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *min = current;
        struct node *j = current->next;
        while (j != NULL) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }
        // swap 
        int temp = current->value;
        current->value = min->value;
        min->value = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
   // User input
    printf("How many elements in your list? : ");
    scanf("%d", &length);

    struct node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        n_node(&head, current_val);
    }

    printf("Unsorted list : ");
    print_ll(head);

    selSort(&head);

    printf("Sorted List : ");
    print_ll(head);
}