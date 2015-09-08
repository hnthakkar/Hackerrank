    #include <iostream>
    using namespace std;
     
    int main()
    {
       int a_year, a_month, a_date, e_year, e_month, e_date;
       cin >> a_date >> a_month >> a_year;
	   cin >> e_date >> e_month >> e_year;
	   if(a_year < e_year){
		   cout << 0 << endl;
	   } else if(a_year == e_year){
    	   if(a_month < e_month) {
    		   cout << 0 << endl;
    	   } else if(a_month == e_month ){
    		   if(a_date <= e_date){
    			   cout << 0 << endl;
    		   } else {
    			   cout << 15*(a_date - e_date) << endl;
    		   }
    	   } else {
    		   cout << 500*(a_month - e_month) << endl;
    	   }
       } else {
    	   cout << 10000 << endl;
       }
       return 0;
    }
