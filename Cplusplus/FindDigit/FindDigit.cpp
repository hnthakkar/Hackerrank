    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	long long int N = 0l, tmp = 0l;
        	cin >> N;
        	int digit = 0;
        	int count = 0;
        	tmp = N;
        	while(tmp){
        		digit = tmp % 10;
        		if(digit != 0) {
        			if(N % digit == 0){
						count++;
					}
        		}
        		tmp = tmp/10;
        	}
        	cout << count << endl;
        }
        return 0;
    }
