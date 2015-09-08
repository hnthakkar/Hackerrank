    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int max = 0, size = 0;
        cin >> max >> size;
        //int input[size];
        int ref[max];
        fill_n(ref, max, 0);
        int tmp = 0;
        for (int i = 0; i < size; i++){
        	cin >> tmp;
        	//cin >> size[i];
        	ref[tmp] = ref[tmp] + 1;
        }

        for(int j = 0; j < max; j++){
        	tmp = ref[j];
        	while(tmp--){
        		cout << " " << j;
        	}
        }
        cout << flush << endl;
    }
