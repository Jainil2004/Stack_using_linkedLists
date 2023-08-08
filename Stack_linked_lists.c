#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct stack{
    struct node* top;
    int size;
};

struct stack* stack_initializer()
{
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->size = 0;
    stack->top = NULL;
    printf("\n**Stack Ready!**\n");

    return stack;    
}

void stack_push(struct stack* stack, int new_node_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    if (new_node == NULL)
    {
        printf("\n**memory allocation failure for node**\n");
        return;
    }
    
    new_node->data = new_node_data;
    
    if (stack->top == NULL)
    {
        new_node->next = NULL;
        stack->top = new_node;
    }
    else
    {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    printf("\n**Node ADDITION to Stack SUCCESSFUL**\n");
    printf("new top data = %d\n", stack->top->data);
}

void stack_pop(struct stack* stack)
{
    if (stack->top == NULL)
    {
        printf("\n**Stack is Empty! Nothing to delete**\n");
        return;
    }
    struct node* ptr = stack->top;
    stack->top = stack->top->next;
    free(ptr);
    printf("\n**Node DELETION from Stack SUCCESSFUL**\n");

    if (stack->top == NULL)
    {
        printf("**stack is now Empty**\n");
        return;
    }
    printf("new top data = %d\n", stack->top->data);
}

int stack_peek(struct stack* stack)
{
    if (stack->top != NULL)
    {
        int temp_holder = stack->top->data;
        printf("\nTop-most element currently in stack = %d\n", temp_holder);
    
        return temp_holder; 
    }
    printf("\n**Stack is empty**\n");

    return -1;
}

int stack_isempty_checker(struct stack* stack)
{
    if (stack->top != NULL)
    {
        printf("\n**Stack is NOT empty**\n");

        return 0;
    }
    printf("\n**Stack is empty**\n");

    return -1;
}

void stack_printer(struct stack* stack)
{
    struct node* ptr = stack->top;
    if (ptr == NULL)
    {
        printf("\n**stack is empty**\n");
    }
    printf("\nTop of Stack -> ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct stack* stack;
    int peeked_value, new_top_data;
    int mode;

    printf("this program depicts the use of singly linked lists for stack implementation\n");

    printf("following are the Options avaliable for list manipulation:\n1.Initialize stack.\n2.push a new element to the stack.\n3.pop the top element from the stack.\n4.peek top of stack.\n5.check if stack is empty or not.\n6.Re-print operations panel.\n7.EXIT.\n");
    
    while(mode != 10)
    {
        printf("please enter the operation you want to perform\n");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            printf("please enter the MAX capacity of the stack you want: \n");

            stack = stack_initializer();
            break;

        case 2:
            printf("please enter the data of the elment you would like to push in stack: \n");
            scanf("%d", &new_top_data);

            stack_push(stack, new_top_data);
            break;

        case 3:
            printf("poping the top-most element in stack :\n");

            stack_pop(stack);
            break;

        case 4:
            peeked_value = stack_peek(stack);
            break;

        case 5:
            stack_isempty_checker(stack);
            break;

        case 6:
            printf("following are the Options avaliable for list manipulation:\n1.Re-Initialize stack.\n2.push a new element to the stack.\n3.pop the top element from the stack.\n4.peek top of stack.\n5.check if stack is empty or not.\n6.Re-print operations panel.\n7.EXIT.\n");
            break;

        case 7:
            goto exit;
            break;

        case 8:
            stack_printer(stack);
            break;

        default:
            printf("operation not found!!! please check the operations list and try again.\n");
            break;
        }
    }

    exit:
    return 0;
}


/*
FOR TESTING ONLY
    stack = stack_initializer();
    stack_pop(stack);
    stack_printer(stack);
    peeked_value = stack_peek(stack);
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    peeked_value = stack_peek(stack);
    stack_push(stack, 40);
    stack_push(stack, 50);
    stack_printer(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_printer(stack);
    peeked_value = stack_peek(stack);


*/