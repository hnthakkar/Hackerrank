    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
        	unsigned long int X = 0l, Y = 0l, B = 0l, W = 0l, Z = 0l;
        	cin >> B >> W >> X >> Y >> Z;
        	unsigned long long int cost = 0l;
        	if(X > Y){
        		if(X-Y>Z){
        			cost = Y*(B+W) + B*Z;
        		} else {
        			cost = B*X + W*Y;
        		}
        	} else if (Y > X){
        		if(Y-X>Z){
        			cost = X*(B+W) + W*Z;
        		}else{
        			cost = B*X + W*Y;
        		}
        	} else {
        		cost = B*X + W*Y;
        	}
        	cout << cost << endl;
        }
        return 0;
    }
