#include<stdio.h>
void fun(int a);//函数声明
//全局变量
int count=1,n=0,bj[10]={0},cc[10]={0};
int main()
{
    scanf("%d",&n);
    fun(count);
    return 0;
}
void fun(int a)//起始数
{
    int i=0;
    if(count==n)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d ",cc[i]);
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(bj[count]==0)
        {
            cc[count]=i;
            bj[count]=1;
            fun(count+1);
            bj[count]=0;
        }
    }
}