#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr);
int isEmpty(struct stack *ptr);
void push(struct stack *ptr, char val);
char pop(struct stack *ptr);
int isOperator(char a);
int preceedence(char a);
int stackTop(struct stack *ptr);
char *infix_to_postfix(char *infix);

int main()
{
    char *infix;
    printf("Enter expression: ");
    scanf("%s", infix);

    printf("The postfix is %s\n", infix_to_postfix(infix));
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("stack overflow");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    else
        return 0;
}

int preceedence(char a)
{
    if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else
        return 0;
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

char *infix_to_postfix(char *infix)
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));

    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (preceedence(infix[i]) > preceedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    
    postfix[j] = '\0';
    return postfix;
}