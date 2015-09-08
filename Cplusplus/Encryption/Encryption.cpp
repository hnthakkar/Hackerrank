    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        string input;
        cin >> input;
        int len = input.length();
        int R = floor(sqrt(len));
        int C = ceil(sqrt(len));
        if(R!=C)
        	R+=1;
        int index = 0;
        int count = 0;
        int col = 0;
        while(count < len){
        	cout << input[index];
        	count++;
        	index += R;
        	if(index >= len){
        		index = ++col;
        		cout << " ";
        	}
        }
        cout << flush << endl;
        return 0;
    }
