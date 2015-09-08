    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        string s[] = {"one","two","three","four","five","six","seven","eight","nine","ten",
        				"eleven", "twelve","thirteen","fourteen", "fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
    	int hh = 0, mm =0;
        /*string time;
		cin >> time;
		string delimiter = ":";
		unsigned int pos = time.find(delimiter);
		int hh = atoi((time.substr(0, pos)).c_str());
		time.erase(0,pos+delimiter.length());
		int mm = atoi(time.c_str());*/
        cin >> hh >> mm;
		string w;
		if(mm == 0){
			w = s[hh-1] + " o' clock";
		}else if(mm < 30){
			if(mm == 1){
				w = s[mm-1] + " minute past " + s[hh-1];
			} else if(mm == 15){
				w = "quarter past " + s[hh-1];
			} else if(mm < 21){
				w = s[mm-1] + " minutes past " + s[hh-1];
			} else {
				w = "twenty " + s[(mm%10)-1] + " minutes past " + s[hh-1];
			}
		} else if(mm > 30){
			mm = 60 - mm;
			if(mm == 15){
				w = "quarter to " + s[hh];
			} else if( mm == 1){
				w = "one minute to " + s[hh];
			} else if(mm > 20){
				w = "twenty " + s[(mm%10)-1] + " minutes to " + s[hh];
			} else {
				w = s[mm-1] + " minutes to " + s[hh];
			}
		} else {
			w = "half past " + s[hh-1];
		}
		cout << w << endl;

        return 0;
    }


    /*string part[2];
            	int index = 0;
            	while((pos = time.find(delimiter))!=string::npos){
            		part[index++] = time.substr(0, pos);
            		cout << part[index] << "or " << time.substr(0, pos) << endl;
            		time.erase(0,pos+delimiter.length());
            	}
            	cout << time << endl;*/
