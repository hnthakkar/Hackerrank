    #include<bits/stdc++.h>
    using namespace std;

    int main() {
		int R = 0, C = 0;
		cin >> R >> C;
		cin.ignore();
		int row[R][C];
		for (int i = 0; i < R; i++){
			string s;
			getline(cin,s);
			istringstream iss(s);
			string sub;
			iss >> sub;
			for(unsigned int j = 0; j < sub.length(); j++){
				//cout << "Value : " << sub.at(j) << endl;
				row[i][j] = (int)sub.at(j) - 48;
				//cout << row[i][j] << "or " << sub.at(j) - 48 << endl;
			}
		}
		int max = 0, maxCount = 0;
		for(int i = 0; i < R-1; i++){
			for(int j = i+1; j < R; j++){
				int count = 0;
				for(int c = 0; c < C; c++){
					//cout << row[i][c] << ":" << row[j][c] << endl;
					if(row[i][c] || row[j][c])
						count++;
				}
				if(count > max){
					max = count;
					maxCount = 1;
				} else if (count == max){
					maxCount++;
				}
			}
		}
		cout << max << endl << maxCount << endl;
        return 0;
    }
