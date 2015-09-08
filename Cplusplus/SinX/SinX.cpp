    #include <iostream>
	#include <iomanip>
	#include <math.h>
    using namespace std;
     
    /*
     * sin x = x - x^3/3! + x^5/5! - x^6/6!....
     */

    int factorial(int n) {
		if (n == 0) {
			return 1;
		}
		return n * factorial(n - 1);
    }

    int main() {
    	double x = 0l;
    	int d = 0;
    	cin >> x >> d;

    	double result = 0;
    	int initSign = 1;
    	double counter = 1.0;
    	for (int i = 1; i < d; i++ ){
    		result += initSign * ((pow(x,counter))/factorial(i));
    		counter++;
    		initSign *= -1;
    	}
    	cout << fixed << setprecision(d) << result << endl;
        return 0;
    }


