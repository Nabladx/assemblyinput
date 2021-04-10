#include <stdio.h>

int main(void){
        int arr[2][2];
        for (int i = 0;i < 2;i++)
        {
                for (int j = 0;j < 2;j++)
                {
                        arr[i][j] = 0;
                }
        }
        int num;
        for (int i = 0;i < 2;i++)
        {
                for (int j = 0;j < 2;j++)
                {
                        scanf("%d", &num);
                        asm(
                                "movl %1, %%ebx;"
                                "movl %%ebx, %0;"
                                : "=r" (arr[i][j])
                                : "r" (num)
                                : "%ebx"
                        );
                }
        }
        for (int i = 0;i < 2;i++)
        {
                for (int j = 0;j < 2;j++)
                {
                        printf("%d", arr[i][j]);
                }
        }
        return 0;
}
