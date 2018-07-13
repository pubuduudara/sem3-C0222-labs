#include <stdio.h>

int main(){
	FILE *fin, *fout;

	fout = fopen("test.txt", "w");
	fprintf(fout,"%d %lf %s\n", 123, 44.55, "Hello");
	fclose(fout);

	fin = fopen("test.txt", "r");
	int i;
	double d;

	char msg[80];
	fscanf(fin, "%d %lf %s", &i, &d, msg);
	printf("i is %d\n", i);
	printf("d is %lf\n", d);
	printf("msg is %s\n", msg);
	fclose(fin);
}
