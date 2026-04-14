#include <stdio.h>
#define M 7
#define N 7
int maze[M][N]={{1,1,1,1,1,1,1},
				{1,0,0,0,1,0,1},
				{1,0,1,1,1,0,1},
				{1,0,0,0,0,0,1},
				{1,0,1,0,1,1,1},
				{1,0,0,0,0,0,1},
				{1,1,1,1,1,1,1}},row_s=1,col_s=1,row_e=5,col_e=5,success=0;
struct{
    int dx,dy;
} wy[4]={{0,1},{1,0},{0,-1},{-1,0}};//右,下,左,上方向
void print(int row,int col){
    int i;
	printf("(%d,%d)\n",row,col);
	maze[row][col]=4;//显示过修改为4，避免走回头路
    if(row==row_e&&col==col_e) 
		return;
	for(i=0;i<=3;i++)
		if(maze[row+wy[i].dx][col+wy[i].dy]==2)
			print(row+wy[i].dx,col+wy[i].dy);
}
/********************************/
void visit(int row, int col)
{
    int i;
    if(row<0||row>=M||col<0||col>=N)
    {
        return;//越界
    }
    if(row==row_e&&col==col_e)
    {
        success=1;//找到出口
        maze[row][col]=2;//标记出口
        print(row_s,col_s);//打印路径
        return;//结束
    }
    if(maze[row][col]==0)//当前为可走的路径
    {
        maze[row][col]=2;//标记为已访问
        for(i=0;(i<=3)&&success==0;i++)//按顺序找下一个点，避免乱递归
        {
            visit(row+wy[i].dx,col+wy[i].dy);
        }
        if(success==0)//没有找到出口，回退
        {
            maze[row][col]=3;//回退
        }
    }
}
/********************************/
void main(){    
	visit(row_s,col_s);
    printf("\n迷宫状态:\n");
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}