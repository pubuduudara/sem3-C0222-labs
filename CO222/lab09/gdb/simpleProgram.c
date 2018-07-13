
// Stepping through the debugger and break points

#include <stdio.h>
void test1(); // function prototype has to declare before the main function
int main()
{
	int var1=0;
	int var2=5; 
	for(var1 = 0; var1< 5; var1++,var2++)
	{
		printf("main function\n");
		test1();
	}
	return 0;
}

void test1()
{
	printf("Inside sub function\n");
	
}
