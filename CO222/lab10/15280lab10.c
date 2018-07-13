#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node_t{
	int val;
	char word[200];
	struct node_t * next;
}node;

int find_max_val(node * head){ // function will return the current maximum word length the word
    node * current = head->next;
    int x=0;	
    while (current != NULL) {
    	if(x<current->val){
    		x=current->val;
    	}
    current = current->next;

    }	
    return x;
}



void print_max_word(node * head){ // function will print the current word with maximum word lenght
    node * current = head->next;
    int current_max_len=find_max_val(head);
    while (current != NULL) {
    	if(current->val==current_max_len){
    		printf("%s\n",current->word);
    		current->val=-1; // update the node value to -1
    		break; // through breaking the loop word appears first will output
    	}
    current = current->next;
	}	
}



int number_of_nodes(node * head){ //function will return the number of nodes in the linked list
	int x=0;
	node * current = head->next;
	while (current != NULL) {
		x++;
	current=current->next;
	}
	return x;
}
 


void update(node * head){ // update function will remove non alphabatic characters
	node * current = head->next;
	while(current!= NULL){
		int indx=0;
		char updated_word[current->val];
		updated_word[current->val]='\0';
		int index=0;
		int i;
		for(i=0;i<(strlen(current->word));i++){
			if(isalpha(current->word[i])!=0){
				updated_word[indx]=current->word[i];
				indx++;
			}
		}
		strcpy(current->word,updated_word);
		current->val=strlen(updated_word);
	current = current->next;
	}
} 


node * head=NULL;					// creating the linked list
int main(int argc, char **argv){
	FILE *in;
	in = fopen(argv[1],"r");
	char text[200];	
	head = (node*)malloc(sizeof(node));
	fscanf(in,"%s",text);
	head->next= (node*)malloc(sizeof(node));
	head->next->val=strlen(text);
	strcpy(head->next->word,text);
	node * n=head->next;
	while( fscanf(in,"%s",text) !=EOF){
		n->next= (node*)malloc(sizeof(node));
		n=n->next;
		n->val=strlen(text);
		strcpy(n->word,text);
	}
	n->next=NULL;
	update(head);
	int count;
	for(count=1;count<=number_of_nodes(head);count++){
		print_max_word(head);
	}
	fclose(in);
	return 0;	


}