#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	BLACK in WHITE background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}
void donut_(int c1,int c2,int r);
void print_1(int n1,int n2){
	int row=1;
	while(row<=8){
		int col=1;
		while(col<=8){
			if(col%2!=0){
				textcolor(BRIGHT,BLACK,n1);
				printf("        ");
			}else{
				textcolor(BRIGHT,BLACK,n2);
				printf("        ");
			}
		col++;
		}

	row++;
	textcolor(RESET, WHITE, BLACK);
	printf("\n");
	}
}

void print_2(int n1,int n2){
	int row=1;
	while(row<=8){
		int col=1;
		while(col<=8){
			if(col%2!=0){
				textcolor(BRIGHT,BLACK,n1);
				printf("        ");
			}else{
				textcolor(BRIGHT,BLACK,n2);
				printf("        ");
			}
		col++;
		}

	row++;
	textcolor(RESET, WHITE, BLACK);
	printf("\n");
	}

}
void donut_(int c1,int c2,int r){
    int i=0;
    int j=0;
    int grid[100][100]={};
    for(i=0;i<r+1;i++){

        int len=(r*r)-(i*i)*0.5;
        for(j=0;j<len;j++){
            grid[r+i][r+j]=1;
            grid[r-i][r-j]=1;
            grid[r+i][r-j]=1;
            grid[r-i][r+j]=1;

        }
    }
    for(i=0;i<(r/2);i++){
        int len=((r*r*0.4)-i*i)*0.5;
        for(j=0;j<len;j++){
            grid[r+i][r+j]=1;
            grid[r-i][r-j]=1;
            grid[r+i][r-j]=1;
            grid[r-i][r+j]=1;
        }
    }
    for(i=1;i<(2*r);i++){
        for(j=1;j<(2*r);j++){
            int b=grid[i][j];
            if(b==1){
                textcolor(BRIGHT,c2,c1);
                printf(" ");
            }else{
                textcolor(BRIGHT,c1,c2);
                printf(" ");
            }
        }
        textcolor(RESET, WHITE, BLACK);
        printf("\n");
    }
}

int clo_number(char col[]);

int main(int argc, char **argv){
	if(argc<4){
		printf("Not enough arguments\n");
    }else if(argc>4){
        printf("Too many arguments\n");
    }else if(clo_number(argv[2])==8){
		printf("Background color is not available\n");
	}else if(clo_number(argv[3])==8){
		printf("Foreground color is not available\n");
	}else{
        int fgg=clo_number(argv[2]);
        int bgg=clo_number(argv[3]);
        if(strcmp(argv[1],"checker")==0){

            int x=1;
            while(x<=8){
                if(x%2==0){
                    print_1(fgg,bgg);

                }else{
                    print_2(bgg,fgg);

                }
            x++;
            }
            textcolor(RESET, WHITE, BLACK);

            return 0;
        }else if(strcmp(argv[1],"donut")==0){
            int radius=0;
            scanf("%d",&radius);
            donut_(bgg,fgg,radius);
        }else{
            printf("Requested figure is not available\n");
        }
    }
}



int clo_number(char col[]){
    if(strcmp(col,"black")==0){
        return 0;
    }else if(strcmp(col,"red")==0){
        return 1;
    }else if(strcmp(col,"green")==0){
        return 2;
    }else if(strcmp(col,"yellow")==0){
        return 3;
    }else if(strcmp(col,"blue")==0){
        return 4;
    }else if(strcmp(col,"magenta")==0){
        return 5;
    }else if(strcmp(col,"cyan")==0){
        return 6;
    }else if(strcmp(col,"white")==0){
        return 7;
    }else{
        return 8;
    }


}
