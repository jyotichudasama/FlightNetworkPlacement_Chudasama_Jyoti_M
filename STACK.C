/*
Write a program to simulate the push/pop functionality of a Stack. The requirements are-
a) It should be possible to PUSH numbers (0 - 9) on the stack only in the proper sequence. Meaning, the allowed sequence is
PUSH 0, PUSH 1, PUSH 2, PUSH 3, PUSH 4, PUSH 5, PUSH 6, PUSH 7, PUSH 8, PUSH 9. It should not be possible to skip
numbers in between. PUSH 2, PUSH 4 is not allowed.
b) Given a random pattern of numbers, the program should be able to validate if it is possible to generate the given pattern
using a number of PUSH - POP operations. For example: the pattern 4 3 2 1 0 9 8 7 6 5 is achievable using the following
PUSH - POP sequence PUSH 0, PUSH 1, PUSH 2, PUSH 3, PUSH 4, POP 4, POP 3, POP 2, POP 1, POP 0, PUSH 5, PUSH 6, PUSH 7, PUSH 8,
PUSH 9, POP 9, POP 8, POP 7, POP 6, POP 5 The results from the POP commands can be printed on the console to show the pattern.
This is a valid pattern and can be achieved using PUSH - POP
*/

#include<conio.h>
#include<stdio.h>

int mystack[10];	// Array holding the elements of the stack
int top = -1;		//	Top of the stack

int push(int * t, int item)	// item is element to be pushed onto the stack
{
	/* Return 1 for successful PUSH  &  0 for unsuccessful PUSH*/
	int temp,top;	// To hold the top element before pushing item
	
	top = *t;	// Content of t into top
	
	if(top == 9)	// Maximum size exceeds
	{
		printf("\n Stack is full. You can't Push item\n");
		return 0;
	}
	
	if(item > 9 || item < 0)		// No any number > 9 or < 0 is allowed
	{
		printf("\n Invalid Input. You can enter number that is between 0-9.\n");
		return 0;
	}
	
	if(top == -1)		// Empty stack, so simply pushed item
	{
		top += 1;
		mystack[top] = item;
		*t = top;
		return 1;
	}
	else
	{
		temp = mystack[top];	// Current top element in temp
		if(temp == (item-1) )	// Element to be pushed is in correct order
		{
			top += 1;	// increase top by 1
			mystack[top] = item;
			*t = top;
			return 1;
			
		}
		else
		{
			printf("\n You can't enter this number as it is not following the correct order.\n");
			return 0;
		}
	}
	
}

int pop(int * t)
{
	/* Return poped element for successful POP  &  -1 for unsuccessful POP. */
	int item,temp;  // To hold poped element
	temp = *t;
	if(temp == -1)
	{
		printf("\n Empty Stack. There is nothing to pop.\n");
		return -1;
	}
	else
	{
	
		item = mystack[temp];
		temp -= 1;
		*t = temp;	// decrease top by 1
		return item;	// returned poped element
	}
}

int main()
{
	int ch = 0,ret_val,item;
	int *ptr;
	ptr = &top;
	
	clrscr();
	printf("\n***************************");
	printf("\n\n  IMPLEMENTATION OF STACK\n\n");
	printf("***************************\n");
	while(ch != 3)		// Run till option to exit is choose
	{
		printf("\n You Can: 1.PUSH   2.POP   3.Exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter element to be pushed.(should be between 0-9): ");
				scanf("%d",&item);
				ret_val = push(ptr,item);
				if( ret_val == 1)
					printf("\n Element pushed succesfully.\n");
				break;
				
			case 2:
				ret_val = pop(ptr);
				if(ret_val != -1)
					printf("\n %d is poped.\n",ret_val);
				break;
			
			case 3:
				printf("\n Exiting...");
				break;
			
			default:
				printf("\n Invalid Choice.");
				break;
		}
	}
	
	//getch();
	return 1;
	
}