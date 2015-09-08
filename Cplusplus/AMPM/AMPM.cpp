    #include<iostream>
	#include <string.h>
	#include <stdlib.h>

    using namespace std;
     
    //12:00:00AM
    int main()
    {
       string s;
       cin >> s;
       string tmp = s.substr(8,2);
       string hh = s.substr(0,2);
       string mm = s.substr(3,2);
       string ss = s.substr(6,2);
       int i_hh = atoi(hh.c_str());
       if(tmp == "PM"){
    	   if(i_hh < 12){
    		   i_hh += 12;
    	   }
       } else {
    	   if(i_hh >= 12){
    		   i_hh -= 12;
    	   }
       }
       cout.fill('0');
       cout.width(2);
       cout << i_hh << ":" + mm + ":" + ss << endl;
    	return 0;
    }
