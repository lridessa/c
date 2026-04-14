#include<stdio.h>

int n=0, bj[10]={0}, cc[10]={0};

void fun(int wz, int depth) {
    int i;
    
    // 打印缩进，表示递归深度
    for(i = 0; i < depth; i++) printf("  ");
    printf("进入 fun(wz=%d)\n", wz);

    if(wz > n) {
        for(i = 0; i < depth; i++) printf("  ");
        printf("得到一个排列: ");
        for(i = 1; i <= n; i++) printf("%d ", cc[i]);
        printf("\n");
        return;
    }

    for(i = 1; i <= n; i++) {
        if(bj[i] == 0) {
            for(int j = 0; j < depth; j++) printf("  ");
            printf("尝试放 %d 到位置 %d\n", i, wz);
            
            cc[wz] = i;
            bj[i] = 1;// 标记数字 i 已使用
            fun(wz + 1, depth + 1);
            bj[i] = 0;
            
            for(int j = 0; j < depth; j++) printf("  ");
            printf("回溯，解锁位置 %d 的 %d\n", wz, i);
        }
    }
    
    for(int j = 0; j < depth; j++) printf("  ");
    printf("退出 fun(wz=%d)\n", wz);
}

int main() {
    scanf("%d", &n);
    printf("%d的全排列:\n", n);
    fun(1, 0);
    return 0;
}