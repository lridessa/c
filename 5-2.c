#include<stdio.h>
void fun(int wz);//函数声明
//全局变量
int n=0,bj[10]={0},cc[10]={0};
int main()
{
    scanf("%d",&n);
    printf("%d的全排列:\n",n);
    fun(1);
    return 0;
}
void fun(int wz)
{
    int i=0;
    if(wz>n)
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
        if(bj[i]==0)
        {
            cc[wz]=i;
            bj[i]=1;
            fun(wz+1);
            bj[i]=0;
        }
    }
}