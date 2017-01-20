#include<stdio.h>
#include<ctype.h>
int main()
{
    int i=0;
    char ch;
    puts("Input an integer followed by a char:");
    // 读取字符直到遇到结束符或者非数字字符
    while((ch = getchar()) != EOF && isdigit(ch))
    {
        i = 10 * i + ch - 48;  // 转为整数
    }
    // 如果不是数字，则放回缓冲区
    if (ch != EOF)
    {
        ungetc(ch,stdin);  // 把一个字符退回输入流
    }
    printf("\n\ni = %d, next char in buffer = %c\n", i, getchar());
    return 0;
}