    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
       int M = 0, N = 0;
       long long int R = 0;
       cin >> M >> N >> R;
       int mat[M][N];
       for(int i = 0; i < M; i++){
    	   for(int j = 0; j < N; j++){
    		   cin >> mat[i][j];
    	   }
       }
       int i = 0, j = 0, istart = 0, jstart = 0;
       int count = 0, loop = 0;
       if(M < N){
    	   loop = M / 2;
       } else {
    	   loop = N / 2;
       }
       int MOri =  M, NOri = N, ROri = R;
       while(M > 0 && N > 0 && count <= loop){
    	   int tmp[2*(M+N)-4];
    	   int index = 0;
    	   while(index < 2*(M+N)-4){
    		   if(i == istart){
    			   if(j < jstart + N-1){
    				   tmp[index++] = mat[i][j++];
    			   } else {
    				   tmp[index++] = mat[i++][j];
    			   }
    		   } else if(j == jstart + N-1){
    			   if(i < istart + M-1){
    				   tmp[index++] = mat[i++][j];
    			   } else {
    				   tmp[index++] = mat[i][j--];
    			   }
    		   } else if(i == istart + M-1){
    			   if(j > jstart){
    				   tmp[index++] = mat[i][j--];
    			   } else {
    				   tmp[index++] = mat[i--][j];
    			   }
    		   } else if(j == jstart){
    			   if(i > istart){
    				   tmp[index++] = mat[i--][j];
    			   } else {
    				   tmp[index++] = mat[i][j];
    			   }
    		   }
    	   }
    	   /*for(int x = 0; x < 2*(M+N)-4; x++) {
    		   cout << tmp[x] << endl;
    	   }*/

    	   R = ROri % (2*(M+N)-4);
    	   int ifil = istart, jfil = jstart, tmpFillIndex = R;
    	   int filCount = 0;
    	   while(filCount < (2*(M+N)-4)){
    		   if(ifil == istart){
    			   if(jfil < jstart + N-1){
    				   mat[ifil][jfil++] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   } else {
    				   mat[ifil++][jfil] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   }
    		   } else if(jfil == jstart + N-1){
    			   if(ifil < istart + M-1){
    				   mat[ifil++][jfil] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   } else {
    				   mat[ifil][jfil--] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   }
    		   } else if(ifil == istart + M-1){
    			   if(jfil > jstart){
    				   mat[ifil][jfil--] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   } else {
    				   mat[ifil--][jfil] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   }
    		   } else if(jfil == jstart){
    			   if(ifil > istart){
    				   mat[ifil--][jfil] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   } else {
    				   mat[ifil][jfil] = tmp[(tmpFillIndex++)%(2*(M+N)-4)];
    				   filCount++;
    			   }
    		   }
    	   }

    	   M = M -2;
    	   N = N - 2;
    	   i = j = istart = jstart = ++count;
       }

       for(int x = 0; x < MOri; x++){
    	   for(int y = 0; y < NOri; y++){
    		   if(y == 0)
    			   cout << mat[x][y];
    		   else
    			   cout << " " << mat[x][y];
    	   }
    	   cout << endl;
       }
       cout << flush << endl;
       return 0;
    }
