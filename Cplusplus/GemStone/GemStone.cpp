#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noOfGems = 0;
    cin >> noOfGems;
    string stones[noOfGems];
    for(int i = 0; i < noOfGems; i++) {
        cin >> stones[i];
    }

    int finalCount[26] = {};
    for (int i = 0; i < noOfGems; i++) {
    	string cur = stones[i];
    	int len = cur.length();
    	int occurence[26] = {};
    	for (int j = 0; j < len; j++){
    		char ch = cur.at(j);
    		occurence[(int) toupper(ch) - 65] = 1;
    	}
    	for (int k = 0; k < 26; k++){
    		if(occurence[k] == 1)
    			finalCount[k] += 1;
    	}
	}

    int count = 0;
    for(int i = 0; i < 26; i++ ){
        if(finalCount[i] == noOfGems)
        	count++;
    }
    cout << count << endl;
    return 0;
}
