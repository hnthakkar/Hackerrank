    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int N;
        cin>>N;
        int stick[N];
        int min = 1001;
        int max = 0;
        for(int i = 0; i < N; i++){
        	cin >> stick[i];
        	if(stick[i] < min)
        		min = stick[i];
        	if(stick[i] > max)
        		max = stick[i];
        }
        cout << N << endl;

        while(max != 0){
        	int newMin = 1001, newMax = 0, count = 0;
        	for(int i = 0; i < N; i++){
        		stick[i] -= min;
        		if(stick[i] > 0){
        			count++;
        			if(stick[i] < newMin){
        				newMin = stick[i];
        			}
        			if(stick[i] > newMax){
        			    newMax = stick[i];
        			}
        		}
        	}
        	if(count)
        		cout << count << endl;
        	min = newMin;
        	max = newMax;
        }
        return 0;
    }
