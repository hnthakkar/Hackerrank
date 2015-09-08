    #include <bits/stdc++.h>
    using namespace std;
     
    int height(int n) {
        int height = 1;
        for(int x = 1; x <= n; x++){
        	if(x%2 != 0){
        		height *= 2;
        	} else {
        		height += 1;
        	}
        }
    	return height;
    }

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	 int n;
        	 cin >> n;
        	 cout << height(n) << endl;
        }
        return 0;
    }
