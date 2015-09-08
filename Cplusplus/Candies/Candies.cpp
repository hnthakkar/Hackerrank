	#include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	long long num = 0;
        	int days = 0;
        	cin >> num >> days;
        	for (int i = 0; i < days; i++)
        	{
        		if(num%2 == 0){
        			num /= 2;
        		} else {
        			num = num - (num + 1)/2;
        		}
        		num = num - num/4;
        	}
        	cout << num << endl;
        }
        return 0;
    }
