	#include<iostream>
	using namespace std;
     
    int main()
    {
    	int i = 0, N = 0, K=0;
    	cin >> N;
    	char c[N];
    	cin >> c;
    	cin >> K;
    	K = K % 26;
    	while(c[i]){
    		int tmp = 0;
			if((int) c[i] >= 97 && (int) c[i] <= 122) {
				tmp = (int) c[i] + K;
				if(tmp > 122)
					tmp = 96 + tmp - 122;
				c[i] = (char)tmp;
			} else if ((int) c[i] >= 65 && (int) c[i] <= 90) {
				tmp = (int) c[i] + K;
				if(tmp > 90)
					tmp = 64 + tmp - 90;
				c[i] = (char) tmp;
			}
			i++;
    	}
    	cout << c << endl;
        return 0;
    }
