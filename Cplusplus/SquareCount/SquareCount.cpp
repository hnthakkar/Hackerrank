    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	unsigned long long int lower = 0l, higher = 0l;
        	cin >> lower >> higher;
        	int numLow = sqrt(lower);
        	int count = 0;
        	while(pow(numLow, 2) <= higher){
        		if(pow(numLow, 2) >= lower && pow(numLow, 2) <= higher)
        			count++;
        		numLow++;
        	}
        	cout << count << endl;
        }
        return 0;
    }
