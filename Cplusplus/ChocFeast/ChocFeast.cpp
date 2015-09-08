    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	int N = 0, C = 0, M = 0;
        	cin >> N >> C >> M;
        	int count = N/C;
        	int wrapper = N/C;
        	while(wrapper >= M){
        		count += wrapper/M;
        		wrapper = wrapper/M + wrapper%M;
        	}
        	cout << count << endl;
        }
        return 0;
    }
