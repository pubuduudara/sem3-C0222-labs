// Fix the bugs

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int value;
	struct node * next;
};

typedef struct node Node;

int main()
{
	Node head;
	Node* iterator = &head;	
	
	// Create a liked list with 10 elements
	int i = 0;
	for(i = 0; i<11 ; i ++)
	{
		if(i==10){
			iterator->next=NULL;
					
		}else{		
			Node* newNodep;
			newNodep=(Node*)malloc(sizeof(Node)); // Inorder to make a linked list the node has to be created
			iterator->next = newNodep;
			newNodep->value = i;
			iterator = newNodep;}
	}
	
	// Printing the values 
	//iterator->next=NULL;	
	//iterator = &head;
	while(iterator->next != NULL)
	{
		printf("Value %d\n", iterator->value);
	}
}
