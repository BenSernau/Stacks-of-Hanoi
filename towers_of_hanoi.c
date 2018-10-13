//Stack implementation stolen from https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

// C program for array implementation of stack 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
// A structure to represent a stack 
struct Stack 
{ 
    char label;
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity, char label) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    stack->label = label;
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   
	return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   
	return stack->top == -1;  
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
    {
        return; 
    }

    stack->array[++stack->top] = item;  
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
    {
        return INT_MIN; 
    }

    return stack->array[stack->top--]; 
} 

int peek(struct Stack* stack)
{
	if (isEmpty(stack)) 
    {
        return INT_MIN; 
    }

	return stack->array[stack->top];
}

void solve(int n, struct Stack* from, struct Stack* to, struct Stack* other)
{
	if(n == 1)
	{
		printf("\nmoved disc %d from rod %c to rod %c", n, from->label, to->label);
		push(to, pop(from));
		return;
	}

	solve(n - 1, from, other, to);
	printf("\nmoved disc %d from rod %c to rod %c", n, from->label, to->label);
	push(to, pop(from));
	solve(n - 1, other, to, from);


}

// Driver program to test above functions 
int main() 
{ 
    struct Stack* stackLeft = createStack(100, 'A'); 
    struct Stack* stackMiddle = createStack(100, 'B');
    struct Stack* stackRight = createStack(100, 'C');

    int diskNum = 7;

    for (int i = 1; i < diskNum + 1; i++)
    {
    	push(stackLeft, i);
    }

  	solve(diskNum, stackLeft, stackRight, stackMiddle);

    return 0; 
} 

/*Non-Stack Solution

#include <stdio.h> 
  
void solve(int n, char from_rod, char to_rod, char other_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Moved disk 1 from %c to %c", from_rod, to_rod); 
        return; 
    } 

    solve(n - 1, from_rod, other_rod, to_rod); 
    printf("\n Moved disk %d from %c to %c", n, from_rod, to_rod); 
    solve(n - 1, other_rod, to_rod, from_rod); 
} 
  
int main() 
{ 
    int plateNum = 4;
    solve(plateNum, 'A', 'C', 'B');
    return 0; 
}*/

