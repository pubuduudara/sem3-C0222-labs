#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define black 		0
#define red		1
#define green		2
#define yellow		3
#define blue		4
#define magenta		5
#define cyan		6
#define	white		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}


void print_1(int n1,int n2){
	int row=1;
	while(row<=8){
		int col=1;
		while(col<=8){
			if(col%2!=0){
				textcolor(BRIGHT,BLACK,n2);
				printf("        ");
			}else{
				textcolor(BRIGHT,BLACK,n1);
				printf("        ");
			}
		col++;
		}

	row++;
	textcolor(RESET, white, black);
	printf("\n");
	}
}

void print_2(int n1,int n2){
	int row=1;
	while(row<=8){
		int col=1;
		while(col<=8){
			if(col%2!=0){
				textcolor(BRIGHT,BLACK,n2);
				printf("        ");
			}else{
				textcolor(BRIGHT,BLACK,n1);
				printf("        ");
			}
		col++;
		}

	row++;
	textcolor(RESET, white, black);
	printf("\n");
	}

}

int main(int argc, char **argv){

	int x=1;
	while(x<=8){
		if(x%2==0){
			print_1();

		}else{
			print_2();

		}
	x++;
	}
	textcolor(RESET, white, black);

	return 0;


}


