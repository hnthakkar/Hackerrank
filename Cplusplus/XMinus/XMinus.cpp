#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
 * 1/(1-x) = 1 + x + x2 + x3.....
 */

int main() {
	double x;
	int d = 0;
	cin >> x >> d;
	double result = 0.0;
	for(int i = 0; i < d; i++){
		result = pow(x,i);
	}
	cout << result << endl;
	return 0;
}


/*
#include <stdio.h>

int main()
{
	int d;
	float x, Prec = 1, Sum = 1, Term;

	printf("Enter the value of x: ");
	scanf("%f", &x);

	printf("Enter the value d: ");
	scanf("%d", &d);

	while(d--)				// Calculate the significant digit
		Prec /= 10;

	Term = x;				// Equating the variable to second term of series

	while((Sum+Term) - Sum >= Prec)		// Calculate till difference is less than precision
	{
		Sum += Term;
		Term *= x;
	}

	printf("%f\n", Sum);

return 0;
}*/
