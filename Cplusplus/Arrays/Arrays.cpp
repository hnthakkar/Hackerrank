    #include<bits/stdc++.h>
    using namespace std;
     
    void Print(int * start, int * end, int ** smallest, int ** largest){
    	if(start == end){
    		smallest = 0;
    		largest = 0;
    	}

    	*smallest = start;
    	*largest = start;
    	for(;start != end; start++){
    		printf("%d\n", *start);
    		if(**largest < *start){
    			*largest = start;
    		}
    		if(**smallest > *start){
    			*smallest = start;
    		}
    	}
    }

    int main()
    {
        int num[] = {1,2,3,7,4};
        int len = sizeof(num)/sizeof(num[0]);

        int *start = num;
        int *end = start + len;
        int * smallest = 0;
        int * largest = 0;

        Print(start, end, &smallest, &largest);

        cout << "min : " << *smallest << ", max : " << *largest << endl;
        //printf("min : %d, max: %d", *smallest, *largest);
        /*for(; p != end; p++){
        	printf("%d\n", *p);
        }*/
        return 0;
    }
