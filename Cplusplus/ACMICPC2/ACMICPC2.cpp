    #include<bits/stdc++.h>
    using namespace std;

    int binToDecimal(string num) {
    	return 21;
    }

    int oneCount(int num) {
    	int count = 0;
    	while(num){
    		if(num % 2 == 1){
    			count++;
    		}
    		num = num / 2;
    		if(num == 1){
    			count++;
    			break;
    		}
    	}
    	return count;
    }

    int main() {
		int R = 0, C = 0;
		cin >> R >> C;
		string tmp;
		int row[R];
		for (int i = 0; i < R; i++){
			cin >> tmp;
			row[i] = binToDecimal(tmp);
		}
		int max = 0, count = 0;
		for(int i = 0; i < R; i++){
			for(int j = i; j < R; j++){
				if((row[i] | row[j]) > max){
					max = row[i] | row[j];
					count = 1;
				} else if ((row[i] | row[j]) == max){
					count++;
				}

			}
		}
		cout << oneCount(max) << endl << count << endl;
        return 0;
    }
