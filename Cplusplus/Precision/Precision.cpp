    #include<iostream>
	#include <iomanip>

    using namespace std;
     
    int main()
    {
        int N;
        cin >> N;
        int positive = 0, negative = 0, zero = 0;
        for(int i = 0; i < N; i++){
        	int tmp;
        	cin >> tmp;
        	if(tmp > 0)
        	{
        		positive++;
        	} else if (tmp < 0)
        	{
        		negative++;
        	} else {
        		zero++;
        	}
        }
        double max = N;
        cout << fixed << setprecision(4) << positive/max << endl << negative/max << endl << zero/max << endl;
        return 0;
    }
