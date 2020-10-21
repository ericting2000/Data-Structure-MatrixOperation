#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"
int main(void)
{
    int matrix_num = 0;
    printf("Data Structure HW3: Matrix Operation\n\n");
    int command = 10;
    printf("請選擇操作：(1)輸入矩陣 (2)檢視矩陣 (3)檢視子矩陣 (4)檢視轉置矩陣 (5)矩陣加法 (6)方陣次方乘法 (7)結束程式\n");
    while (scanf("%d", &command) == 1){
        if (command == 1){
            matrix_num = insert_matrix(matrix_num);
            //printf("matrix_num is now %d\n", matrix_num);
        }
        if (command == 2){
            read_matrix(matrix_num);
        }
        if (command == 3){
            submatrix(matrix_num);
        }
        if (command == 4){
            transposition(matrix_num);
        }
        if (command == 5){
            addition(matrix_num);
        }
        if (command == 6){
            expo(matrix_num);
        }
        if (command == 7){
            printf("BYEBYE\n");
            exit(0);
        }
        printf("請選擇操作：(1)輸入矩陣 (2)列印矩陣 (3)列印子矩陣 (4)列印轉置矩陣 (5)矩陣加法 (6)方陣次方乘法 (7)結束程式\n");
    }
    return 0;
}