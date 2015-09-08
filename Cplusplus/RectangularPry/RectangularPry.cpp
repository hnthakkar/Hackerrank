    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            double X,Y,Z;
            cin >> X >> Y >> Z;
            double A, B, C;
            if(X>Y){
                A = (X-Y+Z)/2;
                B = X-A;
                C = Z-A;
            } else {
                C = (Y-X+Z)/2;
                A = Z-C;
                B = Y-C;
            }
            printf("%.2f\n", 2*(A*B + B*C + C*A));
        }
        return 0;
    }



