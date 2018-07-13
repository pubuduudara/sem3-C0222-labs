#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

int main(int argc, char **argv){

	
	textcolor(RESET, WHITE, RED);
	int row=1;
	while(row<=64){
		int col=1;
		while(col<=8){
			if(row/8!=0){
				if(col/2!=0){
					textcolor(RESET, WHITE, RED);
					printf("        \n");
				}else{
					textcolor(RESET, GREEN, YELLOW);
					printf("        \n");
				}
			}else{
				if(col/2!=0){
					textcolor(RESET, GREEN, YELLOW);
					printf("        \n");
				}else{
					textcolor(RESET, WHITE, RED);
					printf("        \n");

				}
			}
			col++;
		}
		row++;
	}

	return 0;


}
