#include<stdio.h>
int find=0;//全局变量，表示是否找到出口
void digui(int a[7][7],int x,int y,int endx,int endy);
void printmath(int a[7][7],int x,int y);
void printFinalMap(int a[7][7]);
void print(int a[7][7]);
int main()
{
    int a[7][7]={
            {1,1,1,1,1,1,1},
            {1,0,0,1,0,0,1},
            {1,0,1,1,1,0,1},
            {1,0,0,0,0,0,1},
            {1,0,1,0,1,1,1},
            {1,1,0,0,0,0,1},
            {1,1,1,1,1,1,1}};
    digui(a,1,1,5,5);
    if (find) 
    {
        printf("\n路径坐标:\n");
        printmath(a, 1, 1);
        printf("\n");
    } 
    else 
    {
        printf("\n未找到路径!\n");
    }
    // 输出最终地图
    printf("\n探索迷宫地图:\n");
    printFinalMap(a);
    printf("\n迷宫状态:\n");
    print(a);
    return 0;
}
void digui(int a[7][7],int x,int y,int endx,int endy)
{
   if(a[x][y]==0)//0表示可以走
   {
       a[x][y]=2;//2表示已经走过了
       if(x==endx&&y==endy)//如果走到了出口
       {
            find=1;      
            printf("成功\n");
            return;//输出路径
       }
       else//如果没有走到出口
       {
           digui(a,x,y+1,endx,endy);//向右走
           if(find==0)//如果向右走不通
           {
               digui(a,x+1,y,endx,endy);//向下走
           }
           if(find==0)//如果向下走不通
           {
               digui(a,x,y-1,endx,endy);//向左走
           }
           if(find==0)//如果向左走不通
           {
               digui(a,x-1,y,endx,endy);//向上走
           }
           if(find==0)//如果向上也走不通
           {
               a[x][y]=3;//回退
           }
       }
   }
}
void printmath(int a[7][7],int x,int y)
{
   if(x<0||x>6||y<0||y>6)
     {
        return;
     }
     if(a[x][y]==2)
     {
        a[x][y]=4;//4表示路径
        printf("(%d,%d) ",x,y);
        if(x==5&&y==5)
        {
            return;
        }
        // 按顺序找下一个点，避免乱递归
        if(a[x][y+1]==2)
            printmath(a,x,y+1);
        else if(a[x+1][y]==2)
            printmath(a,x+1,y);
        else if(a[x][y-1]==2)
            printmath(a,x,y-1);
        else if(a[x-1][y]==2)
            printmath(a,x-1,y);
            
     }
}
// 打印最终的迷宫地图
void printFinalMap(int a[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (a[i][j] == 1) {
                printf("■ "); // 墙
            } else if (a[i][j] == 4) {
                printf("● "); // 路径
            } else {
                printf("X "); // 未走区域
            }
        }
        printf("\n");
    }
}
// 打印迷宫状态
void print(int a[7][7])
{
   for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)        
        {
            printf("%d ",a[i][j]);
        }       
        printf("\n");
    } 
}  
