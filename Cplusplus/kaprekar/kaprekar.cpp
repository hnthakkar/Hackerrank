    #include <bits/stdc++.h>
    using namespace std;

    int* getIntArray(unsigned long long int num, int* sizeArg){
    	int size = 0;
    	unsigned long long int tmp = num;
    	if(tmp < 0){
    		size = 0;
    	} else {
			while(tmp){
				tmp /= 10;
				size++;
			}
    	}
    	*sizeArg = size;
    	int* retArray = new int[size];
    	int index = 0;
    	while(num){
			retArray[index++] = num % 10;
			num = num/10;
		}
    	return retArray;
    }

    int main()
    {
        int lower = 0, upper = 0;
        cin >> lower >> upper;
        unsigned long long int sq = 0l;
        bool found = false;
        for(int i = lower; i <= upper; i++){
        	if(i == 1){
        		cout << i;
        		found = true;
        		continue;
        	}

        	sq = (unsigned long long)i*i;
        	int size = 0;
        	int* sqArray = getIntArray(sq, &size);
        	int index = 0;
        	//while(index < size){
        		if(size%2 == 0){
        			index = size/2;
        		} else {
        			index = (size+1)/2;
        		}
        		int lindex = 0, rindex = 0, lsum = 0, rsum = 0, base = 1;
        		while(lindex < index){
        			lsum = sqArray[lindex]*base + lsum;
        			base = base * 10;
        			lindex++;
        		}
        		rindex = index;
        		base = 1;
        		while(rindex < size){
        			rsum = sqArray[rindex]*base + rsum;
        			base = base * 10;
        			rindex++;
				}
        		if(lsum + rsum == i){
        			if(found){
        				cout << " " << i;
        			}else{
        				cout << i;
        			}
        			found = true;
        			//break;
        		}
        		//index++;
        	//}
        }
        if(!found)
        	cout << "INVALID RANGE";
        cout << endl << flush;
        return 0;
    }
