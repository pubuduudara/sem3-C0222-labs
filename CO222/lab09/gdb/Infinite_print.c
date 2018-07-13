// Fix the bugs

#include<stdio.h>
#include<stdlib.h>
int main()
{
	// One person need 1 food.
	// We are going to find the amount of extra food needed.
	// For each aditional food we need to print a message

	int people = 10;
	int food = 8;
	int difference = people - food;
	
	while(difference > 0)
	{
		printf("1 more food needed\n"); // new line is printed
		food++;
		difference = people -food; // difference has to update.if difference do not change it will be a infinite loop
	} 
}
