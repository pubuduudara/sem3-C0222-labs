// Week10_Pow.c
// Compute the nth power of x, where
// n is a non-negative integer.
#include <stdio.h>

double mypow(double, int);

int main(void) {
	double x;
	int n;

	printf("Enter x and n: ");
	scanf("%lf %d", &x, &n);

	printf("mypow(%f, %d) = %f\n", x, n, mypow(x, n));
	return 0;
}

// Compute the nth power of x.
// Precond: n >= 0
double mypow(double x, int n) {
	// to be completed
	if(n==1){
		return x;
	}
	else{
		return x*mypow(x,n-1);
	}

}

