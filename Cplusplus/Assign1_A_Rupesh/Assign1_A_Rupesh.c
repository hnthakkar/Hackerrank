#include<stdio.h>
int main()
{
    long double v_number, eps, diff,neg_root, S, prev_S;
    int i, T;
    eps=0.000000001;
    scanf("%d",&T);
	neg_root=-1.0;
    for(i=0; i<T; i++)
    {
		scanf("%Lf",&v_number);
        if(v_number < 0)
            printf("%Lf\n", neg_root);
        else if (v_number == 0.0)
        {
            S=0.0;
            printf("%Lf\n", S);
        }
        else
        {
                S=v_number/2;
            	do
                {
                    prev_S=S;
                    S=0.5*(prev_S+(v_number/prev_S));
                    diff=S-prev_S;
                    if(diff<0)
                        diff=(-1)*diff;
                }
                while(diff>eps);
                printf("%Lf\n", S);
        }
    }
    return 0;
}
