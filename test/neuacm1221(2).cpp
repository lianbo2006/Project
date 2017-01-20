#include <stdio.h>
#include <stdlib.h>
long M,K;
long dcl;
long ans,t;
main()
{
       freopen("/home/lianbo2006/Project/test/neuacm1221in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1221out.txt","w",stdout);
        int n;
        int i;
        long j;
        scanf("%d",&n);
        for(i = 1;i <= n;i++){
            scanf("%ld %ld %ld",&M,&K,&dcl);
            ans = M / K;
            printf("%ld",ans);
            if(dcl > 0) printf(".");
            ans = M  % K;
            for(j = 1;j <= dcl;j++)
            {
                ans *= 10;
                t = ans / K;
                printf("%ld",t);
                ans %= K;
            }
            printf("\n");
        }
             fclose(stdin);
            fclose(stdout);
    return 0;
}