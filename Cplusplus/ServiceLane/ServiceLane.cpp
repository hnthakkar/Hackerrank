    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int N, T;
        cin >> N >> T;
        int width[N];
        for(int i = 0; i < N; i++){
        	cin >> width[i];
        }
        while(T--)
        {
        	int entry = 0, exit = 0;
        	cin >> entry >> exit;
        	int min = 4;
        	for(int i = entry; i <= exit; i++){
        		if(min > width[i])
        			min = width[i];
        	}
        	cout << min << endl;
        }
        return 0;
    }
