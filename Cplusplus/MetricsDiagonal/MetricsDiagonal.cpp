    #include<iostream>
    using namespace std;
     
    int main()
    {
        int N = 0;
        cin >> N;
        int dia1Sum = 0, dia2Sum = 0;
        int iD1 = 0, jD1 = 0, iD2 = 0, jD2 = N-1;
        for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++) {
        		int tmp;
        		cin >> tmp;
        		if(i == iD1 && j == jD1){
        			dia1Sum += tmp;
        			iD1 += 1;
        			jD1 += 1;
        		}

        		if(i == iD2 && j == jD2){
        			dia2Sum += tmp;
        			iD2 += 1;
        			jD2 -=1;
        		}
        	}
        }

        if(dia1Sum < dia2Sum){
			cout << dia2Sum-dia1Sum << endl;
		} else {
			cout << dia1Sum-dia2Sum << endl;
		}
        return 0;
    }
