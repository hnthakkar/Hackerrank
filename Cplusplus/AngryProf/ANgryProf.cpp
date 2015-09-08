    #include <iostream>
    using namespace std;
     
    int main()
    {
        int t = 0;
        cin >> t;
        while(t--)
        {
        	int N = 0, K = 0;
        	cin >> N >> K;
        	int tmp = 0, count = 0;
        	int cond = 0;
        	for (int i = 0; i < N; i++){
        		cin >> tmp;
        		if(tmp <= 0){
        			count++;
        			if(count >= K){
        				cond = 1;
        				//break;
        			}
        		}
        	}

        	if(cond == 1)
        		cout << "NO" << endl;
        	else
        		cout << "YES" << endl;
        }
        return 0;
    }
