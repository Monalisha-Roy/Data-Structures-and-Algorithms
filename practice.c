#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* insert(struct node* head) {
    int element;
    printf("enter element: ");
    scanf("%d", &element);
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->prev = NULL;
    ptr->data = element;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node* delete(struct node* head) {
    printf("Element deleted: %d\n", head->data);
    struct node* ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
    
}

void display(struct node* head) {
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice;
    do 
    {
        printf("------------------------\n");
        printf("1. insert");
        printf("2. delete\n");
        printf("3. display\n");
        printf("4. quit\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        printf("-------- -------------------\n");
        switch(choice) 
        {
            case 1: head = insert(head); break;
            case 2: head = delete(head); break;
            case 3: display(head); break;
            case 4: exit(1);
            default: printf("enter right choice\n"); break;
        }
    }while(1);
}
