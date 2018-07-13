#include<stdio.h>
#include<stdlib.h>

typedef struct myobject
{
	int values[6];
	int index;
} MyObject;

MyObject* createNewObject()
{
	MyObject* returnValue;
	static MyObject oject; // variable oject is a local variable to the this function.since it is used in the addvalues function,  
	oject.index = 0;       //  it has to make a static variable;
	oject.values[2] = 35;	
	returnValue = &oject;
	return returnValue;
}

int addValues(MyObject* object, int i)
{
	int var1 = 10;
	int var2 = 20;
	int var3 = 30;
	int var4 = 30;
	int var5 = 30;
	int var6 = 30;
	int var7 = 30;

	// Assign some values to the object
	object->index = 1;
	object->values[0] = var1 + i + 2;
	object->values[1] = var2 + i + 8;
	object->values[2] = var3 + i + 4;
	object->values[3] = var3 + i + 4;
	object->values[4] = var3 + i + 4;
	object->values[5] = var3 + i + 4;

	// We havent changed var1, var2, var3 any time
	// Lets just try to print them.
	printf("We are printing the values of var1, var2 & var3.\nSince we didn't changed them they should be 10 20 & 30.\n");
	printf("Values : %d %d %d \n", var1,var2,var3);
}

int main()
{
	int a = 10;
	MyObject* object = createNewObject(); // here it returns the pointer of the oject 
	addValues(object, a); // inorder to access the memory address of the variable in another function the varibale has to be static
	return 0;
}
