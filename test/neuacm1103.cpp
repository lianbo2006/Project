#include <stdio.h>
#include <string.h>

/*自定义的大数表示方法
结构体数组中的每一个int表示一个不超过 10 0000 0000 的数,
它是小于有符号int的最大值的,也就是说把一个很大的数拆分成
多个部分表示,就像我们在做两个数相加时,一位一位相加一样,
我只是用程序9位9位的加,取代人工的1位加法
*/

//要求是不超过1000位Fibonacci数,我这里就取MAX_BIG位,最多能表示
//的Fibonacci位数就是 MAX_BIG*9 = 120*9 = 1080位
//我这里用BIG_INTEGER[0]表示最低位
#define MAX_BIG     120
typedef struct{
    //+1:可能产生最高位进位,但我不管,直接丢弃(不然VS2012会报栈被破坏,
    //栈确实会被破坏,VS2012挻智能的)
    unsigned int big[MAX_BIG+1];
}BIG_INTEGER;

#define BIG_BASE        1000000000         //进制,不知道不要乱改
/*******************************************************
函数:calc@12
功能:a+b -> c, 大数加法
参数:a,b - 加数; c:和
返回:(无)
*******************************************************/
void calc(BIG_INTEGER* a, BIG_INTEGER* b,BIG_INTEGER* c)
{
    unsigned int sum=0;
    int i=0;

    /**************************
    以下循环计算一次加法:
        加数1:abcd
        加数2:efgh
        结果:(a+e+x)(b+f+x)(c+g+x)(d+h+x)
    其中:
        abcd,efgh在这里各代表一个9位数
        x代表来自低位的进位
    ***************************/
    memset(c,0,sizeof(BIG_INTEGER));
    for(i=0; i<MAX_BIG; i++){
        c->big[i] = a->big[i] + b->big[i] + c->big[i];  //做1次9位加,记得加上本身
        c->big[i+1] = c->big[i]/BIG_BASE;               //高位加上结果的进位
        c->big[i] = c->big[i] % BIG_BASE;               //当前位只保留余数
    }
}

/************************************************************
函数:fibonacci@4
功能:计算第n位的菲波那契数值
参数:n:第n位, 最低为1
************************************************************/
void fibonacci(int n)
{
    BIG_INTEGER a = {0};
    BIG_INTEGER b = {0};
    BIG_INTEGER c = {0};
    int i=0;

    if(n<=1){
        printf("%d\n",n==1);
        return;
    }

    //Fibonacci:1,1,2,3,5,8,...
    //为保证第一次计算(n=2)时的结果,所以初值为:a=0,b=1 => c=1
    a.big[0] = 0;
    b.big[0] = 1;

    /**************************
    以下循环计算类似小数的Fibonacci:
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    ***************************/
    for(i=2; i<=n; i++){
        calc(&a,&b,&c);
        memcpy(&a,&b,sizeof(BIG_INTEGER));
        memcpy(&b,&c,sizeof(BIG_INTEGER));
    }
    //该for循环忽略输出从最高位开始的为0的一个数值位(9位)
    //当然, 条件 i>0 是必须的,你知道为什么吗?
    for(i=MAX_BIG-1; c.big[i]==0 && i>0; i--)
        ;
    //对于最高位:不需要输出前导的'0'
    printf("%u", c.big[i--]);
    //然后按9位分解输出每个数值位,这个一定要记得输出前导0,
    //一开始我没注意到,就出了问题
    while(i>=0){
        printf("%09u",c.big[i]);
        i--;
    }
    printf("\n");
}

int main(void)
{
    int n;
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}