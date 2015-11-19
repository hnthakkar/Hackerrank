    #include<bits/stdc++.h>
    using namespace std;
     
    int stringLen(char* start){
    	int length = 0;
    	while(*start++){
    		length++;
    	}
    	return length;
    }
    int main()
    {
        char s[] = "Some string";
        //int * start = s;
        //int size = sizeof(s);
        //int * end = start + size;
        stringLen(s);
        return 0;
    }
