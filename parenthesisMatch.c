#include<stdio.h>
#include<stdlib.h>

typedef struct stack 
{
    int size;
    int top;
    char *arr;
}s;

int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
int parenthesisMatch(char *exp);
void push(struct stack *ptr, char val);
char pop(struct stack *ptr);

int main(void)
{

    char *exp = "7*(58*5)-)";

    if (parenthesisMatch(exp) >= 0)
    {
        printf("Parenthesis is matching\n");
    }
    else
    {
        printf("Parenthesis is not matching\n");
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = sizeof(exp);
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return -1;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
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
        ptr->top --;
        return val;
    }
}