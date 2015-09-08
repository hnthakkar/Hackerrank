#include <bits/stdc++.h>
using namespace std;

int main() {
	int R = 0, C = 0, r = 0, c = 0, T = 0;
	cin >> T;
	while (T--) {
		cin >> R >> C;
		int mat[R][C];
		string line;
		for (int i = 0; i < R; i++){
			cin >> line;
			for(int j = 0; j < C; j++){
				char digit = line.at(j);
				mat[i][j] = digit - '0';
				//cout << mat[i][j];
			}
			//cout << endl;
		}

		cin >> r >> c;
		int smallMat[r][c];
		for (int i = 0; i < r; i++){
			cin >> line;
			for(int j = 0; j < c; j++){
				char digit = line.at(j);
				smallMat[i][j] = digit - '0';
				//cout << smallMat[i][j];
			}
			//cout << endl;
		}

		bool match = false;
		for (int x = 0; x <= R-r; x++) {
			for (int y = 0; y <= C-c; y++)	{
				//cout << mat[x][y] << " == " << smallMat[0][0] << ": " << (mat[x][y] == smallMat[0][0]) << endl;
				//cout << mat[x+r-1][y+c-1] << " == " << smallMat[r-1][c-1] << ": " << (mat[x+r-1][y+c-1] == smallMat[r-1][c-1]) << endl;
				//cout << mat[x+r-1][y] << " == " << smallMat[r-1][0] << ": " << (mat[x+r-1][y] == smallMat[r-1][0]) << endl;
				//cout << mat[x][y+c-1] << " == " << smallMat[0][c-1] << ": " << (mat[x][y+c-1] == smallMat[0][c-1]) << endl;
				if(mat[x][y] == smallMat[0][0] && mat[x+r-1][y+c-1] == smallMat[r-1][c-1] && mat[x+r-1][y] == smallMat[r-1][0] && mat[x][y+c-1] == smallMat[0][c-1]){
					match = true;
					for(int p = 0; p < r; p++ ){
						for(int q = 0; q < c; q++){
							if(mat[x+p][y+q] != smallMat[p][q]){
								match = false;
								break;
							}
						}
						if(!match)
							break;
					}
				}
				if(match)
					break;
			}
			if(match)
				break;
		}

		if(match){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
