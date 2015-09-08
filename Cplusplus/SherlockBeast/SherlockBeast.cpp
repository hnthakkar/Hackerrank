    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	int len = 0;
        	cin >> len;
        	int len5 = 0, len3 = 0;
        	if(len%3 == 0){
        		len5 = len;
        	} else {
				for(int i = 1; i <= len; i++){
					if((len-i)%3==0 && i%5==0){
						len5 = len-i;
						len3 = i;
						break;
					}
				}
        	}
        	for(int x = 0; x < len5; x++){
        		cout << 5;
        	}
        	for (int x = 0; x < len3; x++) {
        		cout << 3;
        	}
        	if(len5 == 0 && len3 == 0)
        		cout << -1;

        	cout << endl;
        }
        return 0;
    }
