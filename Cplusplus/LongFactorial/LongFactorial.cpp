    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int N, carry = 0;
        cin>>N;
        int result[200];
        for(int i = 0; i < 200; i++){
        	result[i] = 0;
        }
        result[0] = 1;
        int lastIndex = 0;
        for(int i = 2; i <=N; i++){
        	lastIndex = 0;
        	for(int j = 0; j < 200; j++){
        		int val = result[j] * i + carry;
        		carry = val/10;
        		result[j] = (val%10);
        		if(result[j] > 0){
        			lastIndex = j;
        		}
        	}
        	while(carry){
        		int tmp = carry%10;
        		carry = carry/10;
        		result[++lastIndex] = tmp;
        	}
        }

        for(int x = lastIndex; x >= 0; x--){
        	cout << result[x];
        }
        cout << endl;
        return 0;
    }



/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, carry = 0;
    cin>>N;
    int result[200];
    result[0] = 1;
    for(int i = 2; i <=N; i++){
    	vector<int>::iterator it = result.begin();
    	for(; it != result.end(); ++it){
    		int val = *it * i + carry;
    		carry = val/10;
    		*it = (val%10);
    	}
    	while(carry){
    		int tmp = carry%10;
    		carry = carry/10;
    		++it;
    		*it = tmp;
    	}
    }
    for(vector<int>::reverse_iterator rit = result.rbegin(); rit != result.rend() ; ++rit){
    	cout << *rit;
    }

    for(unsigned int x = 0; x <result.size(); x++){
    	cout << result[x];
    }
    cout << endl;
    return 0;
}
*/
