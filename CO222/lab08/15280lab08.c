#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    FILE *in;
    int k=atoi(argv[1]);
    in = fopen(argv[2],"r");
    char text[k];
    while( fscanf(in,"%s",text) !=EOF){
        if(k<strlen(text)){
            printf("Word length must be less than screen width \n");
            return 0;
        }

    }









    FILE *fin;
    int i=atoi(argv[1]);
    fin = fopen(argv[2],"r");
    char message[i];
    int count=0;
    int spac;
    while( fscanf(fin,"%s",message) !=EOF){

        char ch = getc (fin);


        int y=strlen(message);
        count+=y+1;


        if(count<=i || count-1==i){

            if(ch=='\n'){

                printf("%s ",message);
                printf("\n");
                count=0;
            }else{
                printf("%s ",message);
            }



        }else{
            printf("\n");
            count=y+1;
            if(ch=='\n'){

                printf("%s ",message);
                printf("\n");
                count=0;
            }else{
                printf("%s ",message);
            }



        }

    }

    fclose(fin);


}

