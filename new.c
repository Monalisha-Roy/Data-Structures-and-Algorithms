#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert();
void delete();
void display();
int que[MAX];
int rear = -1;
int front = -1;

int main() {
    int choice;
    do
    {
        printf("---------------------------------------\n");
        printf("1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------------------\n");
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    } while (1);
    
}

void insert() {
    int add_item;
    if(rear == MAX-1)
    printf("Queue Overflow\n");
    else {
        if(front == -1)
        front = 0;
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear++;
        que[rear] = add_item;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    }
    else {
        printf("Element deleted from queue is: %d\n", que[front]);
        front++;
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Queue is: ");
        for(int i = front; i <= rear; i++)
            printf("%d ", que[i]);
        printf("\n");
    }
}