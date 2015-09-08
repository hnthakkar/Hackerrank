    #include <iostream>
	#include <sstream>
	#include <string.h>
    using namespace std;
     
    int main()
    {
        int PIArray[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,3};

    	int t;
        cin>>t;
        cin.ignore();
        while(t--)
        {
        	string s;
        	bool match = true;
        	getline(cin,s);
        	istringstream iss(s);
        	int index = 0;
        	while(iss){
				string sub;
				iss >> sub;
				int len = 0;
				for(unsigned int i = 0; i < sub.length(); i++){
					if(isalpha(sub.at(i)))
						len++;
				}
				if(len > 0 && len != PIArray[index++]){
					match = false;
					break;
				}
			}

        	if(match){
        		cout << "It's a pi song." << endl;
        	} else {
        		cout << "It's not a pi song." << endl;
        	}
        }
        return 0;
    }


    /*string sArray[] = s.s
            	while(s){
            		if(s.length() != PIArray[i]){
            			match = false;
            			break;
            		}
            		i--;
            		cin >> s;
            	}*/

   /*
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }*/
