#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	struct node* next;
	int value;
} Node;

int findLastNodeValue(Node* head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return head->value; 
}

int main()
{
	Node *node1,*node2;
	node1 = (Node *) malloc(sizeof(Node));	
	//node2 = NULL
	node2=(Node *) malloc(sizeof(Node)); // need to assign memory slot to the node in order to assign value and pointer to the node
	node1->next = node2;
	node2->next=NULL; // Null pointer assign to indicate the end of the linked list
	findLastNodeValue(node1);
	findLastNodeValue(node2);
	return 0;
}
