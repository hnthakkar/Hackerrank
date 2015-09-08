    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int n = 0;
        cin >> n;

        int mat[n][n];
        string line;
        for (int i = 0; i < n; i++){
        	cin >> line;
        	for(int j = 0; j < n; j++){
        		char digit = line.at(j);
        		mat[i][j] = digit - '0';
        	}
        }

        int tmp = 0;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
        		tmp = mat[i][j];
        		if(i == 0 || i == n-1 || j == 0 || j == n-1){
        			cout << mat[i][j];
        		} else if(tmp > mat[i-1][j] && tmp > mat[i][j-1] && tmp > mat[i+1][j] && tmp > mat[i][j+1]){
        			cout << "X";
        		} else {
        			cout << mat[i][j];
        		}
        	}
        	cout << endl;
        }
        return 0;
    }

    //int n = cin.get();
    //cin.get(ch);
    //mat[i][j] = ch - 48;


  /*  string line = 0;
            for (int i = 0; i < n; i++){
            	cin >> line;
            	for(int j = n-1; j >= 0; j--){
            		mat[i][j] = line%10;
            		line /= 10;
            	}
            }*/
