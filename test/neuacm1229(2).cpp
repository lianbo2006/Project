#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int a[6] = {0};
int ans[6];
void search(int k)
{
    int i,j;
    if(k == 6)
    {
        for(i = 1;i <= 5;i++)
            printf("%d",ans[i]);
 
 
        printf("\n");
        return ;
    }
    for(i = 1;i <= 5;i++)
    {
        if(a[i] == 0){
            ans[k] = i;
            a[i] = 1;
            search(k+1);
            a[i] = 0;
        }
    }
}
main()
{
 freopen("/home/lianbo2006/Project/test/neuacm1229out2.txt","w",stdout);
    int i;
    search(1);
    fclose(stdout);
    return 0;
}