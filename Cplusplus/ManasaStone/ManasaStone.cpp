    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	int n = 0, a = 0, b = 0;
        	cin >> n >> a >> b;
        	int size = 2;
        	int * stones = NULL, * tmp = NULL;
        	stones = new int[2]; //2
        	stones[0] = a;
        	stones[1] = b;

        	for(int i = 3; i <= n; i++){
        		tmp = new int[2*size];
        		for(int j = 0; j < size; j++){
        			tmp[j] = stones[j] + a;
        		}
        		for(int j = size; j < 2*size; j++){
        			tmp[j] = stones[j-size] + b;
        		}
        		sort(tmp,tmp+2*size);
        		delete [] stones;
        		stones = NULL;
        		int dupCount = 0;
        		int lastNum = tmp[0];
        		for(int x = 1; x < 2*size; x++){
        			if(tmp[x-1] != -1)
        				lastNum = tmp[x-1];
					if(lastNum == tmp[x]){
						tmp[x] = -1;
						dupCount++;
					}
				}
        		stones = new int[2*size-dupCount];
        		int stoneIndex = 0;
        		for(int x = 0; x < 2*size; x++){
        			if(tmp[x] == -1)
        				continue;
        			stones[stoneIndex++] = tmp[x];
        		}

        		size = 2*size-dupCount;
        	}


        	for(int x = 0; x < size; x++){
        		if(x==0){
        			cout << stones[x];
        			continue;
        		}
        		if(stones[x-1] != stones[x])
        			cout << " " << stones[x];
        	}
        	cout << endl << flush;
        }
        return 0;
    }
