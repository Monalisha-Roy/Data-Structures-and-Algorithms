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
int parenthesisMatch(char *exp);
int match(char a, char b);

int main()
{
    char *exp = "{5*8[8+(7*8)]}";
    // printf("Enter expresion: ");
    // scanf("%s", exp);

    if (parenthesisMatch(exp))
    {
        printf("Parenthesis is Matching\n");
    }
    else
    {
        printf("Parenthesis is not Matching\n");
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
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
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *sp ;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }

            char popped_char = pop(sp);

            if (!match(popped_char, exp[i]))
            {
                return 0;
            }
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

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}