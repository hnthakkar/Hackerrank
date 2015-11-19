    #include<bits/stdc++.h>

    using namespace std;
     
    int main()
    {
        char s[] = "Hello World";
        for(char* p = s; *p; p++){
        	if(isupper(*p))
        		*p = tolower(*p);
        	else
        		*p = toupper(*p);
        }

        cout << s << endl;
        return 0;
    }
