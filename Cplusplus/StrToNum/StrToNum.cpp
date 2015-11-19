 //   #include<bits/stdc++.h>
	#include <iostream>
	#include <stdlib.h>
	#include <ctype.h>

    using namespace std;
     
    int main()
    {
    	double d = atof("123.456");
    	int i = atoi("456");
    	cout << d << i << endl;

    	char * num = "12 0x123 101";
    	char * next = num;

    	int first = strtol(next, &next, 10);
    	int second = strtol(next, &next, 16);
    	int third = strtol(next, &next, 2);

    	cout << first << "\t" << second << "\t" << third << endl;
        return 0;
    }
