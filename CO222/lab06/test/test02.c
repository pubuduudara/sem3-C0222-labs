#include <stdio.h>
#define SIZE 80    // size of string buffer

int main() {
   FILE * pFile;
   char buffer[SIZE];

   pFile = fopen("test.txt" , "r");
   if (pFile == NULL) {
      perror("Error opening file");
   } else {
      while (!feof(pFile)) {
         if (fgets(buffer, SIZE, pFile) == NULL) break;
         fputs (buffer , stdout);
      }
      fclose(pFile);
   }
   return 0;
}
